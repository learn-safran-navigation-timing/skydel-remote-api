
#include "PushTrackEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushTrackEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushTrackEcef::CmdName = "PushTrackEcef";
    const char* const PushTrackEcef::Documentation = "Push a track ecef node. Must be called after BeginTrackDefinition and before EndTrackDefinition.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------------------------------\n"
      "Time int    Node Timestamp in miliseconds\n"
      "X    double X distance from earth-center in meters\n"
      "Y    double Y distance from earth-center in meters\n"
      "Z    double Z distance from earth-center in meters";
    const char* const PushTrackEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushTrackEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushTrackEcef);


    PushTrackEcef::PushTrackEcef()
      : CommandBase(CmdName, TargetId)
    {}

    PushTrackEcef::PushTrackEcef(int time, double x, double y, double z)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
      setX(x);
      setY(y);
      setZ(z);
    }

    PushTrackEcefPtr PushTrackEcef::create(int time, double x, double y, double z)
    {
      return std::make_shared<PushTrackEcef>(time, x, y, z);
    }

    PushTrackEcefPtr PushTrackEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushTrackEcef>(ptr);
    }

    bool PushTrackEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
        ;

    }

    std::string PushTrackEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& PushTrackEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time", "X", "Y", "Z"}; 
      return names; 
    }


    int PushTrackEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushTrackEcef::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushTrackEcef::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushTrackEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushTrackEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushTrackEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
