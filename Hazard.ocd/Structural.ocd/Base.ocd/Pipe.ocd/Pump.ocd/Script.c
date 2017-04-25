/*-- Pump --*/

#include PIPL

local connects, eff, con;
local sources, source_index;
local running;

func Initialize()
{
	SetAction("Pump");
	drains = [];
	sources = [];
	// default power
	power = 2;
}

/* Important for pumps:

   first connection -> source
   second connection -> drain
*/

func Left(int iRepeat, bool solid, bool valve, id pipeId, int iPower, object connect)
{
	if (connects < 2)
	{
		return _inherited(iRepeat, solid, valve, pipeId, iPower, connect);
	}
}

func Right(int iRepeat, bool solid, bool valve, id pipeId, int iPower, object connect)
{
	if (connects < 2)
	{
		return _inherited(iRepeat, solid, valve, pipeId, iPower, connect);
	}
}

func Up(int iRepeat, bool solid, bool valve, id pipeId, int iPower, object connect)
{
	if (connects < 2)
	{
		return _inherited(iRepeat, solid, valve, pipeId, iPower, connect);
	}
}

func Down(int iRepeat, bool solid, bool valve, id pipeId, int iPower, object connect)
{
	if (connects < 2)
	{
		return _inherited(iRepeat, solid, valve, pipeId, iPower, connect);
	}
}

func ConnectTo(object connect, int dir)
{
	if (!connects)
	{
		con = connect;
	}
	if (connects == 1)
	{
		eff = connect;
	}
	connects++;
	return _inherited(connect, dir);
}

/* Public interface */

func UpdateEfflux()
{
	drains = [];
	
	if (eff)
	{
		if (eff == pipe_left)  eff->UpdateSystem(this, PIPE_Right, 2);
		if (eff == pipe_right) eff->UpdateSystem(this, PIPE_Left, 2);
		if (eff == pipe_down)  eff->UpdateSystem(this, PIPE_Up, 2);
		if (eff == pipe_up)    eff->UpdateSystem(this, PIPE_Down, 2);
	}
	
	UpdateConflux();
}

func UpdateConflux()
{
	sources = CreateArray();

	if (con)
	{
		if (con == pipe_left)  con->UpdateSystem(this, PIPE_Right, 1);
		if (con == pipe_right) con->UpdateSystem(this, PIPE_Left, 1);
		if (con == pipe_down)  con->UpdateSystem(this, PIPE_Up, 1);
		if (con == pipe_up)    con->UpdateSystem(this, PIPE_Down, 1);
	}
}

func UpdateSystem(object start, int from, bool pump)
{
	if (pump)
	{
		start->~TwoPumpError();
	}
}


func NewConflux(object next)
{
	PushBack(sources, next);
}


func TwoPumpError()
{
	Message("$Error$", this);
}

/* Do the pumping */

func Pumping()
{
	if (running && drains[0] && sources[0])
	{
		var mat;
		for (var i = 0; i < power; i++)
		{
			mat = ExtractLiquid(AbsX(GetX(sources[source_index])), AbsY(GetY(sources[source_index])));
			drains[drain_index]->CastLiquid(mat, 35);
		}
		
		if (!Random(4))
		{
			Smoke(0, 0, 15);
		}
		if (!Random(4))
		{
			Bubble(AbsX(GetX(sources[source_index])), AbsY(GetY(sources[source_index])));
		}
		
		drain_index++;
		source_index++;
		if (drains[drain_index] == 0)
		{
			drain_index = 0;
		}
		if (sources[source_index] == 0)
		{
			source_index = 0;
		}
	}
}

func On()
{
	running = true;
	Sound("Gear", false, 50, 0, 1);
}

func Off()
{
	running = false;
	Sound("Gear", false, 0, 0, -1);
}

func Status()
{
	return running;
}

/* Console control */

func ConsoleControl(int i)
{
	if (i == 1)
	{
		if (running)
		{
			return "$TurnOff$";
		}
		else
		{
			return "$TurnOn$";
		}
	}
}

func ConsoleControlled(int i)
{
	if (i == 1)
	{
		Access();
	}
}

/* Control by switch */
func Access()
{
	if (running)
	{
		Off();
	}
	else
	{
		On();
	}
}

/* Serialisierung */

func Serialize(array extra) // TODO: Implement proper saving mechanism
{
	_inherited(extra);
	if (running)
		extra[GetLength(extra)] = "On()";
	if (con)
		extra[GetLength(extra)] = ["LocalN(\"con\")=Object(%d)", con];
	if (eff)
		extra[GetLength(extra)] = ["LocalN(\"eff\")=Object(%d)", eff];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// properties

local Name = "$Name$";
local Description = "$Description$";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// actions

local ActMap = {
Pump = {
	Prototype = Action,
	Name = "Pump",
	Procedure = DFA_NONE,
	Directions = 4,
	Length = 4,
	Delay = 0,
	X = 0,
	Y = 0,
	Wdt = 50,
	Hgt = 50,
	FacetBase = 0,
	NextAction = "Hold",
},

};
