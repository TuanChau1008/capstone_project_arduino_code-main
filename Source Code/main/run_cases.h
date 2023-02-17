#include "lift_motor_controller.h"
#include "adjust_position.h"

void pickLeftSide() {
  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);
  delay(40);
  // Follow left line until both left IR sensors are 0
  // then stop and do pickup product for about 15 seconds
  while (IRL1Value == 1 || IRL2Value == 1) {
    IRL1Value = digitalRead(IRL1);
    IRL2Value = digitalRead(IRL2);
    delay(40);
    lineFollowLeft();
    if (IRL1Value == 0 && IRL2Value == 0) {
      stopBot(500);
      break;
    }
  }

  // Pickup product
  pickProduct();

  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow right line until one of back IR sensor is 1
  // then stop and break loop
  while (IRR1Value == 1 || IRR2Value == 1) {
    IRR1Value = digitalRead(IRR1);
    IRR2Value = digitalRead(IRR2);
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowRight();
    if (IRB1Value == 1 || IRB2Value == 1) {
      stopBot(1000);
      break;
    }
  }

  adjust_back_position1();
  delay(40);

  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow back line when one of back IR sensor is 1
  // if both sensors are 0 then do drop off product
  while (IRB1Value == 1 || IRB2Value == 1) {
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowBackward();
    if (IRB1Value == 0 && IRB2Value == 0) {
      stopBot(1000);
      break;
    }
  }

  // Drop product
  dropProduct();
}

void pickRightSide() {
  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);
  delay(40);
  // Follow right line until both right IR sensors are 0
  // then stop and do pickup product for about 14 seconds
  while (IRR1Value == 1 || IRR2Value == 1) {
    IRR1Value = digitalRead(IRR1);
    IRR2Value = digitalRead(IRR2);
    delay(40);
    lineFollowRight();
    if (IRR1Value == 0 && IRR2Value == 0) {
      stopBot(500);
      break;
    }
  }

  // Pick up product
  pickProduct();

  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow left line until one of back IR sensor is 1
  // then stop and break loop
  while (IRL1Value == 1 || IRL2Value == 1) {
    IRL1Value = digitalRead(IRL1);
    IRL2Value = digitalRead(IRL2);
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowLeft();
    if (IRB1Value == 1 || IRB2Value == 1) {
      stopBot(1000);
      break;
    }
  }

  adjust_back_position2();
  delay(40);

  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow back line when one of back IR sensor is 1
  // if both sensors are 0 then do drop off product
  while (IRB1Value == 1 || IRB2Value == 1) {
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowBackward();
    if (IRB1Value == 0 && IRB2Value == 0) {
      stopBot(1000);
      break;
    }
  }

  // Drop off product
  dropProduct();
}

void dropLeftSide() {
  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);
  delay(40);
  // Follow left line until both left IR sensors are 0
  // then stop and do pickup product for about 15 seconds
  while (IRL1Value == 1 || IRL2Value == 1) {
    IRL1Value = digitalRead(IRL1);
    IRL2Value = digitalRead(IRL2);
    delay(40);
    lineFollowLeft();
    if (IRL1Value == 0 && IRL2Value == 0) {
      stopBot(500);
      break;
    }
  }

  // Drop product
  dropProduct();

  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow right line until one of back IR sensor is 1
  // then stop and break loop
  while (IRR1Value == 1 || IRR2Value == 1) {
    IRR1Value = digitalRead(IRR1);
    IRR2Value = digitalRead(IRR2);
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowRight();
    if (IRB1Value == 1 || IRB2Value == 1) {
      stopBot(1000);
      break;
    }
  }

  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow back line when one of back IR sensor is 1
  // if both sensors are 0 then do drop off product
  while (IRB1Value == 1 || IRB2Value == 1) {
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowBackward();
    if (IRB1Value == 0 && IRB2Value == 0) {
      stopBot(1000);
      break;
    }
  }
}

void dropRightSide() {
  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);
  delay(40);
  // Follow right line until both right IR sensors are 0
  // then stop and do pickup product for about 14 seconds
  while (IRR1Value == 1 || IRR2Value == 1) {
    IRR1Value = digitalRead(IRR1);
    IRR2Value = digitalRead(IRR2);
    delay(40);
    lineFollowRight();
    if (IRR1Value == 0 && IRR2Value == 0) {
      stopBot(500);
      break;
    }
  }

  // Drop product
  dropProduct();

  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow left line until one of back IR sensor is 1
  // then stop and break loop
  while (IRL1Value == 1 || IRL2Value == 1) {
    IRL1Value = digitalRead(IRL1);
    IRL2Value = digitalRead(IRL2);
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowLeft();
    if (IRB1Value == 1 || IRB2Value == 1) {
      stopBot(1000);
      break;
    }
  }

  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);
  delay(40);
  // Follow back line when one of back IR sensor is 1
  // if both sensors are 0 then do drop off product
  while (IRB1Value == 1 || IRB2Value == 1) {
    IRB1Value = digitalRead(IRB1);
    IRB2Value = digitalRead(IRB2);
    delay(40);
    lineFollowBackward();
    if (IRB1Value == 0 && IRB2Value == 0) {
      stopBot(1000);
      break;
    }
  }
}

void pickupTask(char targetRow, int targetSide) {
  lineFollowCountRow(targetRow);
  adjust_position();

  switch (targetSide) {
    case 'A':
      pickLeftSide();
      break;
    case 'B':
      pickRightSide();
      break;
    default:
      break;
  }
  // Beep twice to indicate task completion
  // then send char 'D' to ESP
  beepTwice();
  Serial3.print('D');
  Serial.println("Job done!");
  stopBot(5000);
}

void dropTask(char targetRow, int targetSide) {
  pickProduct();
  stopBot(500);

  lineFollowCountRow(targetRow);
  adjust_position();

  switch (targetSide) {
    case 'A':
      dropLeftSide();
      break;
    case 'B':
      dropRightSide();
      break;
    default:
      break;
  }

  beepTwice();
  Serial3.print('D');
  Serial.println("Job done!");
  stopBot(5000);
}