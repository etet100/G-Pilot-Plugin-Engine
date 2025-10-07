// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "program.h"

Program::Program() {}

int Program::load(QString file) { return 0; }

int Program::loadString(QString str) { return 0; }

QString Program::path() { return ""; }

bool Program::isLoaded() { return false; }

QPoint Program::lowerBounds() { return QPoint(0,0); }

QPoint Program::upperBounds() { return QPoint(0,0); }

int Program::lineCount() { return 0; }

QString Program::lineAt(int index) { return ""; }

void Program::close() {}

void Program::save(QString file) {}
