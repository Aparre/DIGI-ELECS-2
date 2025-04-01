//please install the ***LiquidCrystal I2C by Frank de Brabander*** library first
// Mga kinakailangang library para sa LCD I2C communication
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set up ng LCD gamit ang I2C address (0x27 o 0x3F) at 16x2 size
const int LDR_PIN = A0;              // Define ng pin kung saan nakakabit ang LDR (Light Dependent Resistor)
// Threshold value para madetect ang hand swipe
const int THRESHOLD = 500;           // Pwedeng i-adjust depende sa ilaw ng kwarto
int memberIndex = 0;                 // Variable para malaman kung anong pangalan ang ipapakita
bool handSwiped = false;             // Boolean flag para malaman kung may kamay na dumaan
unsigned long lastSwipeTime = 0;     // Timer variables para maiwasan ang double-swipe issue
const int swipeCooldown = 500;       // 500ms cooldown para maiwasan ang rapid switching

void setup() {
    lcd.init();       // I-initialize ang LCD screen
    lcd.backlight();  // Buksan ang ilaw ng LCD

    // Magpakita ng unang mensahe
    lcd.setCursor(0, 0);
    lcd.print("Swipe LDR to");
    lcd.setCursor(0, 1);
    lcd.print("see members!");
    
    delay(2000);  // Hintayin ng 2 segundo bago linisin ang screen
    lcd.clear();
}

void loop() {
    int lightValue = analogRead(LDR_PIN);  // Basahin ang light value mula sa LDR

    // Kunin ang kasalukuyang oras gamit ang millis()
    unsigned long currentTime = millis();

    // Kung mabilis na dumaan ang kamay (bumaba ang light level)
    if (lightValue < THRESHOLD && !handSwiped && (currentTime - lastSwipeTime > swipeCooldown)) {  
        handSwiped = true;                      // Markahan na nagkaroon ng swipe
        lastSwipeTime = currentTime;            // I-update ang last swipe time

        // Linisin ang LCD bago mag-display
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Member:");

        // Gumamit ng switch-case para ipakita ang pangalan depende sa memberIndex
        lcd.setCursor(0, 1);
        switch (memberIndex) {
            case 0:
                lcd.print("Christian Gebilaguin");
                break;
            case 1:
                lcd.print("Jenny Hipolito");
                break;
            case 2:
                lcd.print("Raymart Aprre");
                break;
            case 3:
                lcd.print("Angelo Tan");
                break;
            case 4:
                lcd.print("Cheena Ulep");
                break;
        }
        // Lumipat sa susunod na pangalan (babalik sa una pag natapos ang 5)
        memberIndex = (memberIndex + 1) % 5;
    } 
    // Kapag nawala na ang kamay (bumalik ang ilaw), i-reset ang flag
    else if (lightValue > THRESHOLD) {
        handSwiped = false;
    }
}
