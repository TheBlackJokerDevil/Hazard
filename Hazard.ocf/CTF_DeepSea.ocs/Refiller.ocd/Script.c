/*-- Auff�ller --*/


protected func Initialize()
{
  ScheduleCall(this(), "Check", 35);
}

protected func Check()
{
  if(InLiquid()) return(ScheduleCall(this(), "Check", 35));

  for(var i=0 ; i < 10 ; i++)
    InsertMaterial(Material("Water"));
  ScheduleCall(this(), "Check", 2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// properties

local Name = "$Name$";
local Description = "$Description$";
