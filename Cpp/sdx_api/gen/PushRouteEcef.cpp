
#include "gen/PushRouteEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushRouteEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushRouteEcef::CmdName = "PushRouteEcef";
    const char* const PushRouteEcef::Documentation = "Push a route ecef node with speed. Must be called after BeginRouteDefinition and before EndRouteDefinition.";

    REGISTER_COMMAND_FACTORY(PushRouteEcef);


    PushRouteEcef::PushRouteEcef()
      : CommandBase(CmdName)
    {}

    PushRouteEcef::PushRouteEcef(double speed, double x, double y, double z)
      : CommandBase(CmdName)
    {

      setSpeed(speed);
      setX(x);
      setY(y);
      setZ(z);
    }

    PushRouteEcefPtr PushRouteEcef::create(double speed, double x, double y, double z)
    {
      return std::make_shared<PushRouteEcef>(speed, x, y, z);
    }

    PushRouteEcefPtr PushRouteEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushRouteEcef>(ptr);
    }

    bool PushRouteEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Speed"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
        ;

    }

    std::string PushRouteEcef::documentation() const { return Documentation; }


    int PushRouteEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double PushRouteEcef::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void PushRouteEcef::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushRouteEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushRouteEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushRouteEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushRouteEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushRouteEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushRouteEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
