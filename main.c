/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

int lights[MAX_ROOMS];
int temperatures[MAX_ROOMS];
int motion[MAX_ROOMS];
int locks[MAX_ROOMS];

void initializeSystem(int rooms);
void displayMenu();
void controlLights(int rooms);
void readTemperature(int rooms);
void detectMotion(int rooms);
void securitySystem(int rooms);
void analyzeHouseStatus(int rooms);
void autoLock(int rooms);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    initializeSystem(rooms);
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                controlLights(rooms);
                break;
            case 2:
                readTemperature(rooms);
                break;
            case 3:
                detectMotion(rooms);
                break;
            case 4:
                securitySystem(rooms);
                break;
            case 5:
                analyzeHouseStatus(rooms);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    return 0;
}

void initializeSystem(int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temperatures[i] = 22;
        motion[i] = 0;
        locks[i] = 1;
    }
    printf("Initializing system...\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        room -= 1;
        lights[room] = !lights[room];
        printf("Light in Room %d is now %s.\n", room + 1, lights[room] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

void readTemperature(int rooms) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        room -= 1;
        printf("Temperature in Room %d is %d°C.\n", room + 1, temperatures[room]);
        if (temperatures[room] > 30) {
            printf("WARNING: Temperature in Room %d is above 30°C!\n", room + 1);
        }
    } else {
        printf("Invalid room number!\n");
    }
}

void detectMotion(int rooms) {
    int room;
    printf("Enter room number to check motion (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        room -= 1;
        if (motion[room] == 1) {
            printf("Motion detected in Room %d.\n", room + 1);
        } else {
            printf("No motion detected in Room %d.\n", room + 1);
        }
    } else {
        printf("Invalid room number!\n");
    }
}

void securitySystem(int rooms) {
    int room, action;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        room -= 1;
        printf("Enter 1 to Lock or 0 to Unlock: ");
        scanf("%d", &action);
        if (action == 1) {
            locks[room] = 1;
            printf("Room %d is now Locked.\n", room + 1);
        } else if (action == 0) {
            locks[room] = 0;
            printf("Room %d is now Unlocked.\n", room + 1);
        } else {
            printf("Invalid action!\n");
        }
    } else {
        printf("Invalid room number!\n");
    }
}

void analyzeHouseStatus(int rooms) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s Motion, %s\n",
            i + 1,
            lights[i] ? "ON" : "OFF",
            temperatures[i],
            motion[i] ? "Motion Detected" : "No Motion",
            locks[i] ? "Locked" : "Unlocked");
    }
}

void autoLock(int rooms) {}

