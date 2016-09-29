#include Weapon_Base

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// properties

local Name = "$Name$";
local Description = "$Description$";


public func GetCarryMode(object user) {    if (is_selected) return CARRY_Hand; }
public func GetCarrySpecial(object user) { if (is_selected) return "pos_hand2"; }
public func GetCarryBone() { return "Grip"; }
public func GetCarryTransform()
{
	return Trans_Rotate(90, 1, 0, 0);
}


public func Initialize()
{
	_inherited(...);
	firemode_standard =  FiremodeStandard();
	firemode_bouncing =     FiremodeBouncing();
	ChangeFiremode(firemode_standard);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Fire modes

local firemode_standard;
func FiremodeStandard()
{
	return 
	{
		Prototype = firemode_default,
		name = 			"Standard",
		ammo_id = 		Ammo_Standard,
		ammo_load = 	50,

		delay_reload = 	260,
		delay_recover = 3,
		delay_cooldown = 10,

		ammo_usage = 	1,
		ammo_rate = 	2,
		mode = 			WEAPON_FM_Auto,

		condition = 	this.HasNoSlimeUpgrade,

		damage = 		4,
		
		projectile_id = Projectile_Bullet,
		projectile_speed = 300,
		projectile_range = 600,
		projectile_spread = Projectile_Deviation(4, 1),
	};
}


local firemode_bouncing;
func FiremodeBouncing()
{
	return 
	{
		Prototype = firemode_default,
		name = 			"$Bouncing$",
		ammo_id = 		Ammo_Standard,
		ammo_load = 		50,

		delay_reload = 		220,
		delay_recover = 	3,
		delay_cooldown =	10,

		ammo_usage = 		1,
		ammo_rate = 		2,
		mode = 				WEAPON_FM_Auto,

		condition = 		this.HasSlimeUpgrade,

		projectile_id = Projectile_Bullet,
		projectile_speed = 300,
		projectile_range = 600,
		projectile_spread = Projectile_Deviation(4, 1),

		damage = 		4,
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Effects

public func OnFireProjectile(object user, object projectile, proplist firemode)
{
	if (firemode == firemode_standard)
	{
		projectile->Trail(4, 100);
	}
	else if (firemode == firemode_bouncing)
	{
		projectile->Trail(4, 100);
		// TODO: projectile->Reflections(3);
	}
}


public func FireEffect(object user, int angle, proplist firemode)
{
	var dir = user->GetDir() * 2 - 1;

	// muzzle flash
	var x = +Sin(angle, firemode.projectile_distance);
	var y = -Cos(angle, firemode.projectile_distance) + firemode.projectile_offset_y;

	EffectMuzzleFlash(user, x, y, angle, RandomX(20, 50), false, true);
	
	// casing
	x = +Sin(angle, firemode.projectile_distance / 2);
	y = -Cos(angle, firemode.projectile_distance / 2) + firemode.projectile_offset_y;
	
	var cartridge_angle = angle - 35 * dir;

	CreateCartridgeEffect("Cartridge_Pistol", 2, x, y, user->GetXDir() - dir * Cos(cartridge_angle, RandomX(40, 60)), user->GetYDir() - dir * Sin(cartridge_angle, RandomX(40, 60)), 5);
}


public func OnReload() // TODO: callback does not exist yet
{
	Sound("Weapon::Minigun::MiniLoad");
}

public func FireSound(object user, proplist firemode)
{
	Sound("Weapon::Minigun::MiniGun", nil, nil, nil, 1);
	Sound("Weapon::Minigun::MiniTurn", nil, nil, nil, 1);
}

public func OnStartCooldown(object user, proplist firemode)
{
	Sound("Weapon::Minigun::MiniGun", nil, nil, nil, -1);
}

public func OnFinishCooldown(object user, proplist firemode)
{
	Sound("Weapon::Minigun::MiniTurn", nil, nil, nil, -1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Upgrades

public func IsUpgradeable(id upgrade)
{
	if (HasUpgrade(upgrade)) return false;

	return upgrade == Upgrade_Slime;
}

public func GetUpgradeDescription(id upgrade)
{
	if (upgrade == Upgrade_Slime)
	{
		return "$UpgradeToSlime$";
	}
}

public func OnUpgrade(id upgrade)
{
	var clonk = Contained();
  	if(upgrade == Upgrade_Slime)
  	{
		ChangeFiremode(firemode_bouncing);
		if (clonk) clonk->~HelpMessage("$UpgradedToSlime$", clonk);
	}
}

public func OnDowngrade(id upgrade)
{
	if(upgrade == Upgrade_Slime)
	{
    	ChangeFiremode(firemode_standard);
	}
}
