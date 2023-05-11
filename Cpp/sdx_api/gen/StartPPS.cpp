
#include "gen/StartPPS.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of StartPPS
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const StartPPS::CmdName = "StartPPS";
    const char* const StartPPS::Documentation = "Start the simulation at the given PPS count.";

    REGISTER_COMMAND_FACTORY(StartPPS);


    StartPPS::StartPPS()
      : CommandBase(CmdName)
    {}

    StartPPS::StartPPS(int msec)
      : CommandBase(CmdName)
    {

      setMsec(msec);
    }

    StartPPSPtr StartPPS::create(int msec)
    {
      return std::make_shared<StartPPS>(msec);
    }

    StartPPSPtr StartPPS::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<StartPPS>(ptr);
    }

    bool StartPPS::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Msec"])
        ;

    }

    std::string StartPPS::documentation() const { return Documentation; }


    int StartPPS::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    int StartPPS::msec() const
    {
      return parse_json<int>::parse(m_values["Msec"]);
    }

    void StartPPS::setMsec(int msec)
    {
      m_values.AddMember("Msec", parse_json<int>::format(msec, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
