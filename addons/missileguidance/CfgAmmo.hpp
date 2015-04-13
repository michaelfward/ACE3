enum {
    ACE_LOBL = 1,
    ACE_LOAL = 2
};

class CfgAmmo {
    class MissileBase;
    
    class M_PG_AT : MissileBase {
        model = "\A3\Weapons_F\Ammo\Rocket_01_fly_F";
		proxyShape = "\A3\Weapons_F\Ammo\Rocket_01_F";

        irLock = 0;
		laserLock = 0;
		airLock = 0;
		weaponLockSystem = "2 + 16";

		maxSpeed = 720;
		maxControlRange = 5000;
		maneuvrability = 8;
		timeToLive = 60;
		simulationStep = 0.01;
		airFriction = 0.1;
		sideAirFriction = 0.16;
		initTime = 0.002;
		thrustTime = 1.07;
		thrust = 530;
		fuseDistance = 2;
        
		effectsMissileInit = "MissileDAR1";
		effectsMissile = "missile2";
		whistleDist = 4;
		muzzleEffect = "";

        // Turn off arma crosshair-guidance
        manualControl = 0;
        
        // ACE uses these values
        trackOversteer = 1;
        trackLead = 0;
       
        // Begin ACE guidance Configs
        class ACE_MissileGuidance {
            enabled = 1;
            
            minDeflection = 0.005;      // Minium flap deflection for guidance
            maxDeflection = 0.025;       // Maximum flap deflection for guidance
            incDeflection = 0.005;      // The incrmeent in which deflection adjusts.
            //minDeflection = 0.005; 
            //maxDeflection = 0.5;
            //incDeflection = 0.005;
            
            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH", "LIDAR", "SARH", "Optic", "Thermal", "GPS", "SACLOS", "MCLOS" };  
           
            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" }; 
            
            seekerAngle = 90;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier
            
            seekerMinRange = 1;
            seekerMaxRange = 2500;      // Range from the missile which the seeker can visually search
            
            // Attack profile type selection
            defaultAttackProfile = "LIN";
            attackProfiles[] = { "LIN", "DIR", "MID", "HI", "TOP", "PYM" };
        };
    };
    
    class ACE_Hydra70_DAGR : M_PG_AT {
        displayName = "$STR_ACE_Hydra70_DAGR";
		displayNameShort = "$STR_ACE_Hydra70_DAGR_Short";
        
        description = "$STR_ACE_Hydra70_DAGR";
		descriptionShort = "$STR_ACE_Hydra70_DAGR_Desc";
    };
    
    class ACE_Hellfire_AGM114K : ACE_Hydra70_DAGR {
        displayName = "$STR_ACE_Hellfire_AGM114K";
		displayNameShort = "$STR_ACE_Hellfire_AGM114K_Short";
        
		description = "$STR_ACE_Hellfire_AGM114K_desc";
        descriptionShort = "$STR_ACE_Hellfire_AGM114K_desc";
        
        // @TODO: placeholder model to at least make it look different
        model = "\A3\Weapons_F\Ammo\Missile_AT_03_fly_F";
        proxyShape = "\A3\Weapons_F\Ammo\Missile_AT_03_F";
        
        hit = 1400;
        indirectHit = 71;
		indirectHitRange = 4.5;
		effectsMissile = "missile2";
    };
    
    // Titan
    class M_Titan_AT : MissileBase {
        irLock = 0;
		laserLock = 0;
		airLock = 0;

        // Turn off arma crosshair-guidance
        manualControl = 0;
        
        hit = 1400;
        
        // ACE uses these values
        //trackOversteer = 1;
        //trackLead = 0;
       
        // Begin ACE guidance Configs
        class ACE_MissileGuidance {
            enabled = 1;
            
            minDeflection = 0.005;      // Minium flap deflection for guidance
            maxDeflection = 0.25;       // Maximum flap deflection for guidance
            incDeflection = 0.005;      // The incrmeent in which deflection adjusts.
            //minDeflection = 0.005; 
            //maxDeflection = 0.5;
            //incDeflection = 0.005;
            
            // Guidance type for munitions
            defaultSeekerType = "Optic";
            seekerTypes[] = { "Optic" };   
            
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };
            
            seekerAngle = 180;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier
            
            seekerMinRange = 0;
            seekerMaxRange = 2500;      // Range from the missile which the seeker can visually search
            
            // Attack profile type selection
            defaultAttackProfile = "LIN";
            attackProfiles[] = { "TOP", "LIN" };
        };
    };
};