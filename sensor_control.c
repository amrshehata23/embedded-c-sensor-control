/*
 * Embedded C Sensor Control
 *
 * This program simulates a simple embedded control system.
 * It reads simulated temperature and light sensor values,
 * controls a fan and an LED using threshold logic,
 * applies hysteresis to prevent fast ON/OFF switching,
 * and prints system status messages.
 *
 * Project: Embedded C Sensor Control
 * Language: C
 */

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define FAN_ON_TEMPERATURE 28.0f
#define FAN_OFF_TEMPERATURE 27.0f

#define LED_ON_LIGHT_LIMIT 400
#define LED_OFF_LIGHT_LIMIT 450

typedef struct {
    float temperatureC;
    int lightValue;
} SensorData;

typedef struct {
    bool fanOn;
    bool ledOn;
    bool temperatureWarning;
    bool lowLightWarning;
} SystemState;

typedef struct {
    float totalTemperature;
    float maximumTemperature;
    float minimumTemperature;
    int totalLight;
    int maximumLight;
    int minimumLight;
    int temperatureWarnings;
    int lowLightWarnings;
} SimulationStats;

static SensorData sensorSamples[] = {
    {22.5f, 820},
    {24.0f, 760},
    {26.5f, 610},
    {28.2f, 450},
    {29.5f, 390},
    {30.1f, 350},
    {27.8f, 430},
    {25.6f, 580},
    {23.9f, 700},
    {22.8f, 790}
};

void initializeSystemState(SystemState *state);
void initializeStats(SimulationStats *stats, SensorData firstSample);
void updateTemperatureControl(float temperatureC, SystemState *state);
void updateLightControl(int lightValue, SystemState *state);
void updateStats(SimulationStats *stats, SensorData data, SystemState state);
void printSystemStatus(size_t sampleNumber, SensorData data, SystemState state);
void printSummary(SimulationStats stats, size_t sampleCount);

int main(void) {
    const size_t sampleCount = sizeof(sensorSamples) / sizeof(sensorSamples[0]);

    SystemState systemState;
    SimulationStats stats;

    initializeSystemState(&systemState);
    initializeStats(&stats, sensorSamples[0]);

    printf("Embedded C Sensor Control System\n");
    printf("--------------------------------\n");

    for (size_t i = 0; i < sampleCount; i++) {
        updateTemperatureControl(sensorSamples[i].temperatureC, &systemState);
        updateLightControl(sensorSamples[i].lightValue, &systemState);
        updateStats(&stats, sensorSamples[i], systemState);
        printSystemStatus(i + 1, sensorSamples[i], systemState);
    }

    printSummary(stats, sampleCount);

    printf("Simulation finished.\n");

    return 0;
}

void initializeSystemState(SystemState *state) {
    state->fanOn = false;
    state->ledOn = false;
    state->temperatureWarning = false;
    state->lowLightWarning = false;
}

void initializeStats(SimulationStats *stats, SensorData firstSample) {
    stats->totalTemperature = 0.0f;
    stats->maximumTemperature = firstSample.temperatureC;
    stats->minimumTemperature = firstSample.temperatureC;

    stats->totalLight = 0;
    stats->maximumLight = firstSample.lightValue;
    stats->minimumLight = firstSample.lightValue;

    stats->temperatureWarnings = 0;
    stats->lowLightWarnings = 0;
}

void updateTemperatureControl(float temperatureC, SystemState *state) {
    if (!state->fanOn && temperatureC > FAN_ON_TEMPERATURE) {
        state->fanOn = true;
    } else if (state->fanOn && temperatureC < FAN_OFF_TEMPERATURE) {
        state->fanOn = false;
    }

    state->temperatureWarning = temperatureC > FAN_ON_TEMPERATURE;
}

void updateLightControl(int lightValue, SystemState *state) {
    if (!state->ledOn && lightValue < LED_ON_LIGHT_LIMIT) {
        state->ledOn = true;
    } else if (state->ledOn && lightValue > LED_OFF_LIGHT_LIMIT) {
        state->ledOn = false;
    }

    state->lowLightWarning = lightValue < LED_ON_LIGHT_LIMIT;
}

void updateStats(SimulationStats *stats, SensorData data, SystemState state) {
    stats->totalTemperature += data.temperatureC;
    stats->totalLight += data.lightValue;

    if (data.temperatureC > stats->maximumTemperature) {
        stats->maximumTemperature = data.temperatureC;
    }

    if (data.temperatureC < stats->minimumTemperature) {
        stats->minimumTemperature = data.temperatureC;
    }

    if (data.lightValue > stats->maximumLight) {
        stats->maximumLight = data.lightValue;
    }

    if (data.lightValue < stats->minimumLight) {
        stats->minimumLight = data.lightValue;
    }

    if (state.temperatureWarning) {
        stats->temperatureWarnings++;
    }

    if (state.lowLightWarning) {
        stats->lowLightWarnings++;
    }
}

void printSystemStatus(size_t sampleNumber, SensorData data, SystemState state) {
    printf("Sample %lu\n", (unsigned long)sampleNumber);
    printf("Temperature: %.1f C\n", data.temperatureC);
    printf("Light value: %d\n", data.lightValue);
    printf("Fan: %s\n", state.fanOn ? "ON" : "OFF");
    printf("LED: %s\n", state.ledOn ? "ON" : "OFF");

    if (state.temperatureWarning) {
        printf("Warning: High temperature detected.\n");
    }

    if (state.lowLightWarning) {
        printf("Warning: Low light detected.\n");
    }

    printf("\n");
}

void printSummary(SimulationStats stats, size_t sampleCount) {
    printf("Simulation Summary\n");
    printf("------------------\n");
    printf("Average temperature: %.2f C\n", stats.totalTemperature / sampleCount);
    printf("Maximum temperature: %.1f C\n", stats.maximumTemperature);
    printf("Minimum temperature: %.1f C\n", stats.minimumTemperature);
    printf("Average light value: %.2f\n", (float)stats.totalLight / sampleCount);
    printf("Maximum light value: %d\n", stats.maximumLight);
    printf("Minimum light value: %d\n", stats.minimumLight);
    printf("High temperature warnings: %d\n", stats.temperatureWarnings);
    printf("Low light warnings: %d\n", stats.lowLightWarnings);
    printf("\n");
}
