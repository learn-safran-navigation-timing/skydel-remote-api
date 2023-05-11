
#include "gen/PushIntTxTrackEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushIntTxTrackEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushIntTxTrackEcef::CmdName = "PushIntTxTrackEcef";
    const char* const PushIntTxTrackEcef::Documentation = "Push an interference track ecef node. Must be called after BeginIntTxTrackDefinition and before EndIntTxTrackDefinition.";

    REGISTER_COMMAND_FACTORY(PushIntTxTrackEcef);


    PushIntTxTrackEcef::PushIntTxTrackEcef()
      : CommandBase(CmdName)
    {}

    PushIntTxTrackEcef::PushIntTxTrackEcef(int time, double x, double y, double z, const std::string& id)
      : CommandBase(CmdName)
    {

      setTime(time);
      setX(x);
      setY(y);
      setZ(z);
      setId(id);
    }

    PushIntTxTrackEcefPtr PushIntTxTrackEcef::create(int time, double x, double y, double z, const std::string& id)
    {
      return std::make_shared<PushIntTxTrackEcef>(time, x, y, z, id);
    }

    PushIntTxTrackEcefPtr PushIntTxTrackEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushIntTxTrackEcef>(ptr);
    }

    bool PushIntTxTrackEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string PushIntTxTrackEcef::documentation() const { return Documentation; }


    int PushIntTxTrackEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushIntTxTrackEcef::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushIntTxTrackEcef::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushIntTxTrackEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushIntTxTrackEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushIntTxTrackEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string PushIntTxTrackEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void PushIntTxTrackEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
