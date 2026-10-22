#include <stdio.h>
#include <stdint.h>

// CAN H ----/----\-----
// CAN L ----\____/-----

// Simulated hardware register address
volatile int8_t *ACTUATOR_REG = (volatile int8_t *)0x40001000; 

// Simulated placeholder for real hardware register
int8_t simulated_hardware_register = 0;

// Function Prototypes
int8_t velocity_check(uint8_t target_vel, uint8_t current_vel);
void actuator_set(int8_t adjustment_value);

int main(void) {
    // Overriding physical address pointer for local PC simulation testing
    ACTUATOR_REG = &simulated_hardware_register;

    uint8_t target_velocity = 10;
    uint8_t current_velocity = 0;
    int8_t error_adjustment = 0;

    printf("Starting Drum Velocity Control Loop...\n");

    // Loop simulating control over time
    for (int i = 0; i < 5; i++) {
        // Step 1: Calculate the necessary adjustment delta
        error_adjustment = velocity_check(target_velocity, current_velocity);
        
        // Step 2: Write adjustment to hardware
        actuator_set(error_adjustment);
        
        printf("Current: %d rpm | Target: %d rpm | Actuator Set To: %d\n", 
               current_velocity, target_velocity, simulated_hardware_register);

        // Simulate hardware responding and speed increasing closer to target
        current_velocity += 3; 
    }

    return 0;
}

/**
 * Calculates the difference between target and current velocity.
 * Returns a signed adjustment value.
 */
int8_t velocity_check(uint8_t target_vel, uint8_t current_vel) {
    // Safe casting to signed integer to prevent underflow/unsigned bugs
    int16_t error = (int16_t)target_vel - (int16_t)current_vel;
    
    // Safety Bounds Check: Cap the actuator maximum step adjustments
    if (error > 20)  return 20;
    if (error < -20) return -20;
    
    return (int8_t)error;
}

/**
 * Directly writes the calculated adjustment to the memory-mapped register.
 */
void actuator_set(int8_t adjustment_value) {
    // Write directly to physical hardware register address
    *ACTUATOR_REG = adjustment_value;
}

/*** 
Output Example:
Starting Drum Velocity Control Loop...
Current: 0 rpm | Target: 10 rpm | Actuator Set To: 10
Current: 3 rpm | Target: 10 rpm | Actuator Set To: 7
Current: 6 rpm | Target: 10 rpm | Actuator Set To: 4
Current: 9 rpm | Target: 10 rpm | Actuator Set To: 1
Current: 12 rpm | Target: 10 rpm | Actuator Set To: -2

***/

