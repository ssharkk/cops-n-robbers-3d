#pragma once

void ApplyInput();
void ApplyControls(float steer, float gas, int player_id);
Vector3 Steer(float amount, Vector3 target, Vector3 position);
Vector3 EngineGas(float amount, Vector3 target, Vector3 position);