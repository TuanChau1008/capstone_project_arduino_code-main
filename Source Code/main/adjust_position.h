void adjust_position() {
  IRR1Value = digitalRead(IRR1);
  IRR2Value = digitalRead(IRR2);
  IRL1Value = digitalRead(IRL1);
  IRL2Value = digitalRead(IRL2);

  // Check ở ngã tư 2 sensor trái phải có ra khỏi line ko,
  // nếu có lùi về cho đến khi 2 sensor vào line.
  if (IRR1Value == 0 || IRL1Value == 0) {
    while (IRR1Value == 0 || IRL1Value == 0) {
      IRR1Value = digitalRead(IRR1);
      IRL1Value = digitalRead(IRL1);
      moveBackward(70, 75, 100, 95);
      if (IRR1Value == 1 || IRL1Value == 1) {
        stopBot(1000);
        break;
      }
    }
  }
}

void adjust_back_position1() {
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);

  if (IRB1Value == 0 || IRB2Value == 0) {
    while (IRB1Value == 0 || IRB2Value == 0) {
      IRB1Value = digitalRead(IRB1);
      IRB2Value = digitalRead(IRB1);
      moveLeft(100, 105, 115, 105);
      if (IRB1Value == 1 && IRB1Value == 1) {
        stopBot(1000);
        break;
      }
    }
  }
}

void adjust_back_position2() {
  IRB1Value = digitalRead(IRB1);
  IRB2Value = digitalRead(IRB2);

  if (IRB1Value == 0 || IRB2Value == 0) {
    while (IRR1Value == 0 || IRB2Value == 0) {
      IRB1Value = digitalRead(IRB1);
      IRB2Value = digitalRead(IRB1);
      moveRight(100, 105, 115, 105);
      if (IRB1Value == 1 && IRB1Value == 1) {
        stopBot(1000);
        break;
      }
    }
  }
}
