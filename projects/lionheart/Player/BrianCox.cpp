#include "BrianCox.hpp"

lionheart::Placement lionheart::BrianCox::placeUnit(UnitType, StartBox const &box, SituationReport report)
{
  /*Fill this out with instructions on how to place your initial units.  Without
   * changes your units will fill the starting box from top left to bottom right
   * in the order constructed.*/
  /*for (int r = box.minRow; r < box.maxRow; ++r)
    for (int c = box.minCol; c < box.maxCol; ++c)
      if (report.things[r][c].type == SituationReport::SPACE)
        return { r, c };
  return { 0, 0 };
  */
  ++id;
  bool westSide = (box.minCol < static_cast<int>(report.things[0].size() / 2));
  if (westSide)
  {
	  switch (id)
	  {
		  // CROWN
	  case 1: return{ 15, 2 };
			  // KNIGHTS
	  case 2: return{ 10, 4 };
	  case 3: return{ 11, 4 };
	  case 4: return{ 12, 4 };
	  case 5: return{ 17, 4 };
	  case 6: return{ 18, 4 };
	  case 7: return{ 19, 4 };
			  // ARCHERS
	  case 8: return{ 10, 3 };
	  case 9: return{ 10, 5 };
	  case 10:return{ 13, 7 };
	  case 11:return{ 14, 5 };
	  case 12:return{ 15, 5 };
	  case 13:return{ 16, 7 };
	  case 14: return{ 19, 3 };
	  case 15: return{ 19, 5 };
			   // INFANTRY
	  case 16: return{ 14, 6 };
	  case 17: return{ 14, 7 };
	  case 18: return{ 15, 6 };
	  case 19: return{ 15, 7 };
	  case 20: return{ 13, 4 };
	  case 21: return{ 14, 4 };
	  case 22: return{ 15, 4 };
	  case 23: return{ 16, 4 };

	  case 24: return{ 14, 2 };
	  case 25: return{ 15, 3 };
	  case 26: return{ 14, 3 };
	  case 27: return{ 13, 3 };
	  case 28: return{ 16, 3 };
	  case 29: return{ 13, 5 };
	  case 30: return{ 16, 5 };
	  }
  }
  else
  {
	  switch (id)
	  {
		  // CROWN
	  case 1: return{ 15, 27 };
			  // KNIGHTS
	  case 2: return{ 10, 25 };
	  case 3: return{ 11, 25 };
	  case 4: return{ 12, 25 };
	  case 5: return{ 17, 25 };
	  case 6: return{ 18, 25 };
	  case 7: return{ 19, 25 };
			  // ARCHERS
	  case 8: return{ 10, 26 };
	  case 9: return{ 10, 24 };
	  case 10:return{ 13, 22 };
	  case 11:return{ 14, 24 };
	  case 12:return{ 15, 24 };
	  case 13:return{ 16, 22 };
	  case 14: return{ 19, 26 };
	  case 15: return{ 19, 24 };
			   // INFANTRY
	  case 16: return{ 14, 23 };
	  case 17: return{ 14, 22 };
	  case 18: return{ 15, 23 };
	  case 19: return{ 15, 22 };
	  case 20: return{ 13, 25 };
	  case 21: return{ 14, 25 };
	  case 22: return{ 15, 25 };
	  case 23: return{ 16, 25 };

	  case 24: return{ 14, 27 };
	  case 25: return{ 15, 26 };
	  case 26: return{ 14, 26 };
	  case 27: return{ 13, 26 };
	  case 28: return{ 16, 26 };
	  case 29: return{ 13, 24 };
	  case 30: return{ 16, 24 };
	  }
  }
  return{ 0, 0 };
}

  lionheart::Action
lionheart::BrianCox::recommendAction(Unit const & u, SituationReport, Plan p)
{
  /*Fill this out with the behavior you want for your units.  Without changes
   * your units will just wait to be defeated.  Feel free to look at the other provided players for ideas on how to get certain behavior*/
  /*return Action();*/
	  if (u.getType() == CROWN) {
		  return wait();
	  }
	  if (u.getType() == ARCHER)
	  {
		  if (p.hasAttack())
		  {
			  return p.attackEnemy();
		  }
		  return wait();
	  }
	  if (u.getType() == INFANTRY)
	  {
		  if (p.hasAttack())
		  {
			  return p.attackEnemy();
		  }
		  return p.moveToEnemyCrown();
	  }
	  if (u.getType() == KNIGHT)
	  {
		  if (p.hasAttack())
		  {
			  return p.attackEnemy();
		  }
		  return p.moveToEnemyCrown();
	  }
	  return p.attackEnemy();
}

lionheart::Blazon lionheart::BrianCox::getBlazon()
{
  /*Return your blazon here.  In case of conflicts preference will be given to
   * the students that have registered their blazons in class.*/
  return { Color::OR, Color::VERT, Style::BEND, "Brian Cox" };
}
