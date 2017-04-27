#include Library_DefaultScript

func Initialize()
{
	SetGoal(SCENPAR_HAZARD_GOAL);

	_inherited(...);
	SetSkyParallax(0, 15, 15);
	
	CreateDeco();
	CreateReeks();
	CreateLadders();
	CreateJumpPads();
	CreateSpawnPoints();
	CreateWaypoints();
}

func CreateDeco()
{
	CreateObject(CON1, 958, 725, NO_OWNER);
	CreateObject(CON1, 650, 735, NO_OWNER);
	CreateObject(CON1, 758, 735, NO_OWNER);
	CreateObject(CON1, 480, 165, NO_OWNER);
	CreateObject(CON1, 530, 165, NO_OWNER);
	CreateObject(CON1, 495, 130, NO_OWNER);

	CreateObject(CRN1, 335,  60, NO_OWNER)->SetCraneLength(8);
	CreateObject(CRN1, 680,  60, NO_OWNER)->SetCraneLength(10);
	
	CreateObject(GSTA, 278, 570, NO_OWNER);
	CreateObject(GSTA, 228, 570, NO_OWNER);
	CreateObject(GSTA, 178, 570, NO_OWNER);

	CreateObjectAbove(LBGH, 250, 610, NO_OWNER)->GetLight()->TurnOn();
	CreateObjectAbove(LBGH, 730, 660, NO_OWNER)->GetLight()->TurnOn();
	CreateObjectAbove(LBGH, 520, 460, NO_OWNER)->GetLight()->TurnOn();
	CreateObjectAbove(LBGH, 680, 320, NO_OWNER)->GetLight()->TurnOn();
	CreateObjectAbove(LBGH, 450, 200, NO_OWNER)->SetCableLength(150)->GetLight()->TurnOn();
	CreateObjectAbove(LBGH, 730,  60, NO_OWNER)->GetLight()->TurnOn();
	CreateObjectAbove(LBGH, 350,  60, NO_OWNER)->GetLight()->TurnOn();

	CreateObject(FENC, 150, 566, NO_OWNER);
	CreateObject(FENC, 210, 566, NO_OWNER);
	CreateObject(FENC, 270, 566, NO_OWNER);
	CreateObject(FENC, 330, 566, NO_OWNER);
}

func CreateReeks()
{
	CreateObject(Deco_Funnel, 906,  46, NO_OWNER)->SetSize(200);
	CreateObject(Deco_Funnel, 976, 164, NO_OWNER)->SetSize(150);
	CreateObject(Deco_Funnel, 486, 336, NO_OWNER)->SetSize(150);
	CreateObject(Deco_Funnel, 346, 387, NO_OWNER)->SetSize(250);
	CreateObject(Deco_Funnel,  47, 341, NO_OWNER)->SetSize(150);
	CreateObject(Deco_Funnel, 136, 109, NO_OWNER)->SetSize(200);
	CreateObject(Deco_Funnel, 196,  33, NO_OWNER)->SetSize(150);
}

func CreateLadders()
{
//	CreateObject(LADR, 255, 410, NO_OWNER)->Set(9);
//	CreateObject(LADR, 195, 130, NO_OWNER)->Set(9);
//	CreateObject(LADR, 460, 330, NO_OWNER)->Set(5);
//	CreateObject(LADR, 825, 100, NO_OWNER)->Set(7);
//	CreateObject(LADR, 570, 520, NO_OWNER)->Set(6);
}

func CreateJumpPads()
{
	CreateObject(JMPD, 986, 693, NO_OWNER)->Set( 75, -25);
	CreateObject(JMPD, 490, 727, NO_OWNER)->Set( 80, +25);
	CreateObject(JMPD, 482, 727, NO_OWNER)->Set(100, -25);
	CreateObject(JMPD, 618, 627, NO_OWNER)->Set( 99, +35);
	CreateObject(JMPD, 906, 477, NO_OWNER)->Set( 80, -45, -90);
	CreateObject(JMPD, 886, 627, NO_OWNER)->Set( 80, -15);
	CreateObject(JMPD, 834, 497, NO_OWNER)->Set( 60, +25, 90);
	CreateObject(JMPD, 986, 427, NO_OWNER)->Set(120, -75);
	CreateObject(JMPD, 350, 577, NO_OWNER)->Set(100, +60);
	CreateObject(JMPD, 466, 517, NO_OWNER)->Set( 75, -20, -90);
	CreateObject(JMPD, 386, 437, NO_OWNER)->Set(100, +35);
	CreateObject(JMPD, 124, 337, NO_OWNER)->Set( 70, +15);
	CreateObject(JMPD, 825, 477, NO_OWNER)->Set(110, +10);
	CreateObject(JMPD, 254, 277, NO_OWNER)->Set( 85, +32);
	CreateObject(JMPD, 750, 287, NO_OWNER)->Set( 85, +15);
	CreateObject(JMPD, 726, 427, NO_OWNER)->Set( 80, +45);
	CreateObject(JMPD, 494, 427, NO_OWNER)->Set( 80, +15);
}

func CreateSpawnPoints()
{
	// configure spawn points
	var ammo_standard = CreateSpawnPoint(0, 0)->SpawnItem(STAP);
	var ammo_grenade = CreateSpawnPoint(0, 0)->SpawnItem(GRAP);
	var ammo_gasoline = CreateSpawnPoint(0, 0)->SpawnItem(GSAP);
	var ammo_energy = CreateSpawnPoint(0, 0)->SpawnItem(ENAP);
	var ammo_missile = CreateSpawnPoint(0, 0)->SpawnItem(MIAP);
	
	var upgrade_laser = CreateSpawnPoint(0, 0)->SpawnItem(Upgrade_Laser);
	var upgrade_slime = CreateSpawnPoint(0, 0)->SpawnItem(Upgrade_Slime);
	var upgrade_rifle = CreateSpawnPoint(0, 0)->SpawnItem(Upgrade_WeaponPart);
	
	var weapon_pumpgun = CreateSpawnPoint(0, 0)->SpawnItem(Weapon_Pumpgun);
	var weapon_minigun = CreateSpawnPoint(0, 0)->SpawnItem(Weapon_Minigun);
	var weapon_grenade = CreateSpawnPoint(0, 0)->SpawnItem(Weapon_GrenadeLauncher);
	var weapon_flame = CreateSpawnPoint(0, 0)->SpawnItem(Weapon_FlameThrower);
	var weapon_bazooka = CreateSpawnPoint(0, 0)->SpawnItem(Weapon_Bazooka);
	var weapon_energy = CreateSpawnPoint(0, 0)->SpawnItem(Weapon_EnergyRifle);
	var weapon_motegun= CreateSpawnPoint(0, 0)->SpawnItem(Weapon_Motegun);
	var weapon_mine = CreateSpawnPoint(0, 0)->SpawnItem(MINE);
	
	var item_jetpack = CreateSpawnPoint(0, 0)->SpawnItem(Gear_Jetpack);
	var item_medipack = CreateSpawnPoint(0, 0)->SpawnItem(MEDI);
	var item_novodekan = CreateSpawnPoint(0, 0)->SpawnItem(NVDN);
	var item_armor = CreateSpawnPoint(0, 0)->SpawnItem(HARM);
	var item_drone = CreateSpawnPoint(0, 0)->SpawnItem(DRSU);

	// place spawn points
	
	CopySpawnPoint(weapon_pumpgun, 240, 730);
	CopySpawnPoint(ammo_standard, 220, 730);
	CopySpawnPoint(ammo_grenade, 510, 730);
	CopySpawnPoint(weapon_grenade, 710, 630);
	CopySpawnPoint(ammo_grenade, 730, 630);
	CopySpawnPoint(upgrade_slime, 940, 700);
	CopySpawnPoint(weapon_bazooka, 940, 430);
	CopySpawnPoint(ammo_missile, 960, 430);
	CopySpawnPoint(weapon_grenade, 200, 170);
	CopySpawnPoint(ammo_grenade, 220, 170);
	CopySpawnPoint(upgrade_laser, 970, 270);
	CopySpawnPoint(item_drone, 950, 340);
	CopySpawnPoint(weapon_energy, 600, 430);
	CopySpawnPoint(ammo_energy, 620, 430);
	CopySpawnPoint(weapon_mine, 160, 420);
	CopySpawnPoint(weapon_motegun, 200, 250);
	CopySpawnPoint(ammo_energy, 180, 250);
	CopySpawnPoint(upgrade_laser, 490, 110);
	CopySpawnPoint(item_medipack, 680, 170);
	CopySpawnPoint(weapon_minigun, 930, 170);
	CopySpawnPoint(ammo_standard, 910, 170);
	CopySpawnPoint(item_armor, 710, 745);
	CopySpawnPoint(item_jetpack, 150, 580);
	CopySpawnPoint(ammo_gasoline, 170, 580);
	CopySpawnPoint(upgrade_rifle, 140, 510);
	CopySpawnPoint(ammo_energy, 230, 340);
	CopySpawnPoint(ammo_grenade, 670, 290);
	CopySpawnPoint(ammo_standard, 610, 170);
// TODO
//	PlaceBonusSpawnpoint([AEXB], 330, 40, 2000);
//	PlaceBonusSpawnpoint([AMPB], 700, 40, 2000);
//	PlaceBonusSpawnpoint([BSKB, HSTB, HELB, RPFB, INVB], 70, 510);
	
	// remove template spawn points
	ammo_standard->RemoveObject();
	ammo_grenade->RemoveObject();
	ammo_gasoline->RemoveObject();
	ammo_energy->RemoveObject();
	ammo_missile->RemoveObject();
	
	upgrade_laser->RemoveObject();
	upgrade_slime->RemoveObject();
	upgrade_rifle->RemoveObject();

	weapon_pumpgun->RemoveObject();
	weapon_minigun->RemoveObject();
	weapon_grenade->RemoveObject();
	weapon_flame->RemoveObject();
	weapon_bazooka->RemoveObject();
	weapon_energy->RemoveObject();
	weapon_motegun->RemoveObject();
	weapon_mine->RemoveObject();
	
	item_medipack->RemoveObject();
	item_jetpack->RemoveObject();
	item_armor->RemoveObject();
	item_novodekan->RemoveObject();
	item_drone->RemoveObject();
}


func RelaunchLocations()
{
	return 
	[
		{x =  50, y = 720, team = -1},
		{x = 610, y = 690, team = -1},
		{x = 820, y = 610, team = -1},
		{x = 260, y = 570, team = -1},
		{x = 480, y = 500, team = -1},
		{x = 970, y = 330, team = -1},
		{x = 850, y = 160, team = -1},
		{x = 390, y = 140, team = -1}
	];
}

/* KI */

func CreateWaypoints()
{
	var wp1 = CreateWP(326, 579);
	var wp2 = CreateWP(330, 38);
	var wp3 = CreateWP(698, 37);
	var wp4 = CreateWP(190, 169);
	var wp5 = CreateWP(304, 171);
	var wp6 = CreateWP(495, 99);
	var wp7 = CreateWP(758, 170);
	var wp8 = CreateWP(958, 170);
	var wp9 = CreateWP(832, 169);
	var wp10 = CreateWP(750, 288);
	var wp11 = CreateWP(799, 288);
	var wp12 = CreateWP(712, 288);
	var wp13 = CreateWP(646, 287);
	var wp14 = CreateWP(521, 431);
	var wp15 = CreateWP(937, 268);
	var wp16 = CreateWP(949, 338);
	var wp17 = CreateWP(729, 428);
	var wp18 = CreateWP(496, 431);
	var wp19 = CreateWP(969, 267);
	var wp20 = CreateWP(686, 430);
	var wp21 = CreateWP(985, 430);
	var wp22 = CreateWP(932, 429);
	var wp23 = CreateWP(389, 438);
	var wp24 = CreateWP(83, 509);
	var wp25 = CreateWP(113, 437);
	var wp26 = CreateWP(484, 511);
	var wp27 = CreateWP(622, 630);
	var wp28 = CreateWP(883, 630);
	var wp29 = CreateWP(835, 629);
	var wp30 = CreateWP(669, 629);
	var wp31 = CreateWP(982, 697);
	var wp32 = CreateWP(936, 696);
	var wp33 = CreateWP(709, 727);
	var wp34 = CreateWP(229, 728);
	var wp35 = CreateWP(62, 728);
	var wp36 = CreateWP(133, 580);
	var wp37 = CreateWP(445, 727);
	var wp38 = CreateWP(477, 728);
	var wp39 = CreateWP(498, 727);
	var wp40 = CreateWP(534, 727);
	var wp41 = CreateWP(234, 579);
	var wp42 = CreateWP(140, 509);
	var wp43 = CreateWP(362, 576);
	var wp44 = CreateWP(293, 438);
	var wp45 = CreateWP(233, 339);
	var wp46 = CreateWP(125, 335);
	var wp47 = CreateWP(202, 251);
	var wp48 = CreateWP(308, 280);
	var wp49 = CreateWP(258, 281);
	var wp50 = CreateWP(384, 169);
	wp1->AddPath(wp41, Path_MoveTo, -1);
	wp1->AddPath(wp43, Path_MoveTo, 1);
	wp1->AddPath(wp37, Path_Jump, 1);
	wp2->AddPath(wp6, Path_MoveTo, 1);
	wp2->AddPath(wp4, Path_MoveTo, -1);
	wp3->AddPath(wp6, Path_MoveTo, -1);
	wp3->AddPath(wp9, Path_MoveTo, 1);
	wp4->AddPath(wp5, Path_MoveTo, 1);
	wp4->AddPath(wp45, Path_MoveTo, 1);
	wp4->AddPath(wp35, Path_Jump, -1);
	wp5->AddPath(wp50, Path_Jump, 1);
	wp5->AddPath(wp4, Path_MoveTo, -1);
	wp6->AddPath(wp50, Path_MoveTo, -1);
	wp6->AddPath(wp7, Path_MoveTo, 1);
	wp6->AddPath(wp3, Path_Jump, 1, 10, 3);
	wp6->AddPath(wp2, Path_Jump, -1, 10, 2);
	wp7->AddPath(wp9, Path_Jump, 1);
	wp7->AddPath(wp6, Path_MoveTo, -1);
	wp7->AddPath(wp32, Path_MoveTo, 1);
	wp8->AddPath(wp9, Path_MoveTo, -1);
	wp8->AddPath(wp19, Path_MoveTo, 1);
	wp9->AddPath(wp8, Path_MoveTo, 1);
	wp9->AddPath(wp7, Path_Jump, -1);
	wp10->AddPath(wp8, Path_MoveTo, 1);
	wp11->AddPath(wp12, Path_Jump, -1);
	wp11->AddPath(wp16, Path_Backflip, 1);
	wp11->AddPath(wp10, Path_MoveTo, -1);
	wp12->AddPath(wp13, Path_MoveTo, -1);
	wp12->AddPath(wp11, Path_Jump, 1);
	wp12->AddPath(wp10, Path_MoveTo, 1);
	wp13->AddPath(wp14, Path_Jump, -1);
	wp13->AddPath(wp12, Path_MoveTo, 1);
	wp13->AddPath(wp44, Path_Jump, -1, 40, 1);
	wp13->AddPath(wp37, Path_Backflip, -1);
	wp14->AddPath(wp18, Path_MoveTo, -1);
	wp14->AddPath(wp37, Path_Jump, -1);
	wp14->AddPath(wp20, Path_MoveTo, 1);
	wp15->AddPath(wp30, Path_MoveTo, -1);
	wp15->AddPath(wp11, Path_Backflip, -1);
	wp16->AddPath(wp19, Path_Jump, -1);
	wp17->AddPath(wp16, Path_MoveTo, 1);
	wp18->AddPath(wp13, Path_MoveTo, 1);
	wp19->AddPath(wp15, Path_MoveTo, -1);
	wp20->AddPath(wp48, Path_MoveTo, -1, 1, 10);
	wp20->AddPath(wp17, Path_MoveTo, 1);
	wp20->AddPath(wp14, Path_MoveTo, -1);
	wp20->AddPath(wp14, Path_MoveTo, -1);
	wp20->AddPath(wp29, Path_Jump, 1);
	wp21->AddPath(wp20, Path_MoveTo, -1);
	wp22->AddPath(wp21, Path_MoveTo, 1);
	wp22->AddPath(wp19, Path_Jump, -1);
	wp22->AddPath(wp30, Path_Backflip, -1);
	wp23->AddPath(wp13, Path_MoveTo, 1);
	wp24->AddPath(wp25, Path_MoveTo, 1);
	wp24->AddPath(wp35, Path_MoveTo, -1);
	wp25->AddPath(wp44, Path_MoveTo, 1);
	wp25->AddPath(wp24, Path_MoveTo, -1, -1, 5);
	wp25->AddPath(wp35, Path_MoveTo, -1);
	wp26->AddPath(wp41, Path_Backflip, -1);
	wp26->AddPath(wp40, Path_MoveTo, 1);
	wp27->AddPath(wp20, Path_MoveTo, 1);
	wp28->AddPath(wp22, Path_MoveTo, 1);
	wp29->AddPath(wp30, Path_MoveTo, -1);
	wp29->AddPath(wp28, Path_MoveTo, 1);
	wp29->AddPath(wp32, Path_Jump, 1);
	wp30->AddPath(wp29, Path_MoveTo, 1);
	wp30->AddPath(wp27, Path_MoveTo, -1);
	wp30->AddPath(wp40, Path_Jump, -1);
	wp31->AddPath(wp29, Path_MoveTo, -1);
	wp32->AddPath(wp33, Path_MoveTo, -1);
	wp32->AddPath(wp31, Path_MoveTo, 1);
	wp33->AddPath(wp40, Path_MoveTo, -1);
	wp33->AddPath(wp32, Path_MoveTo, 1);
	wp34->AddPath(wp37, Path_MoveTo, 1);
	wp34->AddPath(wp35, Path_MoveTo, -1);
	wp35->AddPath(wp34, Path_MoveTo, 1);
	wp35->AddPath(wp36, Path_Jump, 1);
	wp36->AddPath(wp35, Path_MoveTo, -1);
	wp36->AddPath(wp41, Path_MoveTo, 1);
	wp37->AddPath(wp34, Path_MoveTo, -1);
	wp37->AddPath(wp40, Path_Jump, 1);
	wp37->AddPath(wp38, Path_MoveTo, 1);
	wp38->AddPath(wp41, Path_MoveTo, -1);
	wp39->AddPath(wp30, Path_MoveTo, 1);
	wp40->AddPath(wp33, Path_MoveTo, 1);
	wp40->AddPath(wp37, Path_Jump, -1);
	wp40->AddPath(wp39, Path_MoveTo, -1);
	wp41->AddPath(wp36, Path_MoveTo, -1);
	wp41->AddPath(wp42, Path_Jump, 10, 2, 1);
	wp41->AddPath(wp1, Path_MoveTo, 1);
	wp42->AddPath(wp41, Path_MoveTo, 1);
	wp43->AddPath(wp44, Path_MoveTo, -1);
	wp44->AddPath(wp45, Path_Jump, -1);
	wp44->AddPath(wp25, Path_MoveTo, -1);
	wp44->AddPath(wp23, Path_MoveTo, 1);
	wp45->AddPath(wp44, Path_MoveTo, 1);
	wp45->AddPath(wp46, Path_MoveTo, -1);
	wp46->AddPath(wp47, Path_MoveTo, 1);
	wp47->AddPath(wp48, Path_MoveTo, 1);
	wp47->AddPath(wp45, Path_MoveTo, 1, 1, 10);
	wp47->AddPath(wp14, Path_Jump, 1, 10, 1);
	wp48->AddPath(wp49, Path_MoveTo, -1);
	wp48->AddPath(wp47, Path_Jump, -1);
	wp48->AddPath(wp20, Path_MoveTo, 1, 1, 10);
	wp49->AddPath(wp50, Path_MoveTo, 1);
	wp50->AddPath(wp6, Path_MoveTo, 1);
	wp50->AddPath(wp48, Path_MoveTo, -1);
	wp50->AddPath(wp5, Path_Jump, -1);
}

/* Regelwaehler */

// TODO
//func ChooserFinished()
//{
//	var wp = FindObject(WPCH);
//	if (wp)
//	{
//		// und begrenzte Waren...
//		wp->RemoveWare();
//		wp->AddWare(PIWP); // Pistole
//		wp->AddWare(GLWP); // Granatenwerfer
//		wp->AddWare(MIWP); // Minigun
//		wp->AddWare(BZWP); // Bazooka
//		wp->AddWare(KLAS); // Laser
//		wp->AddWare(KRFL); // Waffenteile
//		wp->AddWare(FLSH); // Taschenlampe
//		wp->AddWare(JTPK); // Jetpack
//		wp->AddWare(HARM); // R�stung
//		wp->AddWare(HSHD); // Schild
//		wp->AddWare(DRSU); // Drone
//		wp->AddWare(MINE); // Mine
//		//wp->SortWare();
//	}
//}

