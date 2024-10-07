#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to categorize the temperature and provide advisory
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors if possible.\n");
    }
}
int main() {
    float temperature;
    int current_scale, target_scale;

    // Input temperature value
    printf("Enter the temperature: ");
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1; // Exit with error code
    }

    // Choose current scale
    printf("Choose the current scale:\n(1) Celsius\n(2) Fahrenheit\n(3) Kelvin\n");
    if (scanf("%d", &current_scale) != 1 || current_scale < 1 || current_scale > 3) {
        printf("Invalid choice. Please choose a valid scale.\n");
        return 1; // Exit with error code
    }

    // Handle invalid temperatures
    if (current_scale == 3 && temperature < 0) {
        printf("Invalid input: Temperature in Kelvin cannot be negative.\n");
        return 1; // Exit with error code
    }

    // Convert input temperature to Celsius
    if (current_scale == 1) { // Celsius
        // No conversion needed, already in Celsius
    } else if (current_scale == 2) { // Fahrenheit
        temperature = fahrenheit_to_celsius(temperature);
    } else if (current_scale == 3) { // Kelvin
        temperature = kelvin_to_celsius(temperature);
    }

    // Output the temperature in Celsius for categorization
    categorize_temperature(temperature);

    // Choose target scale for final output
    printf("Convert to:\n(1) Celsius\n(2) Fahrenheit\n(3) Kelvin\n");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid choice. Please choose a valid scale.\n");
        return 1; // Exit with error code
    }

    // Convert temperature to the target scale
    if (target_scale == 1) {
        printf("Converted temperature: %.2f°C\n", temperature);
    } else if (target_scale == 2) {
        printf("Converted temperature: %.2f°F\n", celsius_to_fahrenheit(temperature));
    } else {
        printf("Converted temperature: %.2fK\n", celsius_to_kelvin(temperature));
    }

    return 0; // Successful execution
}
