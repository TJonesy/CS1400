#ifndef LIONHEART_ACTION_HPP
#define LIONHEART_ACTION_HPP

#include "Map.hpp"
#include "Unit.hpp"
namespace lionheart
{
struct Placement
{
  int row;
  int col;
};

class ActionImpl
{
public:
  virtual ~ActionImpl()=default;
  virtual bool apply(std::shared_ptr<const Map> const & map,
                  Unit & actor,
                  std::vector<std::shared_ptr<Unit>> & allies,
                  std::vector<std::shared_ptr<Unit>> & enemies)=0;
  virtual std::unique_ptr<ActionImpl> clone() const =0;
  virtual void output(std::ostream&) const=0;
};



class Action
{
public:
  Action():pImpl(nullptr){}
  Action(std::unique_ptr<ActionImpl>&& impl):pImpl(std::move(impl)){}
  Action(Action const & other):pImpl(other.pImpl?other.pImpl->clone():nullptr){}
  Action& operator=(Action const& other)
  {
    if (&other == this) return *this;
    pImpl = other.pImpl ? other.pImpl->clone() : nullptr;
	return *this;
  }
  std::unique_ptr<ActionImpl> pImpl;
  bool operator()(std::shared_ptr<const Map> const& map,
                  Unit& actor,
                  std::vector<std::shared_ptr<Unit>>& allies,
                  std::vector<std::shared_ptr<Unit>>& enemies)
  {
    if (pImpl) {
      return pImpl->apply(map, actor, allies, enemies);
    }
    return false;
  }
  void output(std::ostream&) const;
  void input(std::istream&);
};


Action turn(Direction d);
Action move(int distance);
Action wait();
Action attack(Placement p);
}

std::ostream& operator<<(std::ostream&,lionheart::Action const &);
std::istream& operator>>(std::istream&,lionheart::Action &);
#endif
