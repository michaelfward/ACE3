#include "script_component.hpp"

GVAR(hardpointGroupsCache) = [] call CBA_fnc_createNamespace;
GVAR(configTypesAdded) = [];
["ace_settingsInitialized", {
    TRACE_2("settingsInit",GVAR(level),GVAR(supply));
    ["LandVehicle", "Init", {_this call FUNC(initSupplyVehicle)}, true, ["StaticWeapon"], true] call CBA_fnc_addClassEventHandler;
    ["ReammoBox_F", "Init", {_this call FUNC(initSupplyVehicle)}, true, [], true] call CBA_fnc_addClassEventHandler;
}] call CBA_fnc_addEventHandler;

["ace_unconscious", LINKFUNC(handleUnconscious)] call CBA_fnc_addEventHandler;
["vehicle", {
    params ["_unit"];
    [_unit] call FUNC(dropAmmo);
}] call CBA_fnc_addPlayerEventHandler;

if (isServer) then {
    addMissionEventHandler ["HandleDisconnect", {params ["_unit"]; [_unit] call FUNC(dropAmmo)}];
};

[QGVAR(makeDummyEH), LINKFUNC(makeDummy)] call CBA_fnc_addEventHandler;
[QGVAR(rearmEntireVehicleSuccessLocalEH), LINKFUNC(rearmEntireVehicleSuccessLocal)] call CBA_fnc_addEventHandler;
[QGVAR(rearmSuccessLocalEH), LINKFUNC(rearmSuccessLocal)] call CBA_fnc_addEventHandler;

