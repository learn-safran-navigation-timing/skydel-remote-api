
#include "StartPPS.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of StartPPS
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const StartPPS::CmdName = "StartPPS";
    const char* const StartPPS::Documentation = "Start the simulation at the given PPS count.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -------------------------------------------------------------\n"
      "Msec int  The number of ms after PPS to wait before starting simulation";
    const char* const StartPPS::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(StartPPS);
    REGISTER_COMMAND_TO_FACTORY_IMPL(StartPPS);


    StartPPS::StartPPS()
      : CommandBase(CmdName, TargetId)
    {}

    StartPPS::StartPPS(int msec)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& StartPPS::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Msec"}; 
      return names; 
    }


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
