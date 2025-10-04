// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "program.h"

Program::Program() {}

int Program::load(QString file) {}

int Program::loadString(QString str) {}

QString Program::path() {}

bool Program::isLoaded() {}

QPoint Program::lowerBounds() {}

QPoint Program::upperBounds() {}

int Program::lineCount() {}

QString Program::lineAt(int index) {}

void Program::close() {}

void Program::save(QString file) {}
