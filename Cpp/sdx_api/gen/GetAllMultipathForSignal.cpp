
#include "gen/GetAllMultipathForSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMultipathForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMultipathForSignal::CmdName = "GetAllMultipathForSignal";
    const char* const GetAllMultipathForSignal::Documentation = "Get all multipath ID for the specified signal.";

    REGISTER_COMMAND_FACTORY(GetAllMultipathForSignal);


    GetAllMultipathForSignal::GetAllMultipathForSignal()
      : CommandBase(CmdName)
    {}

    GetAllMultipathForSignal::GetAllMultipathForSignal(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    GetAllMultipathForSignalPtr GetAllMultipathForSignal::create(const std::string& signal)
    {
      return std::make_shared<GetAllMultipathForSignal>(signal);
    }

    GetAllMultipathForSignalPtr GetAllMultipathForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMultipathForSignal>(ptr);
    }

    bool GetAllMultipathForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetAllMultipathForSignal::documentation() const { return Documentation; }


    int GetAllMultipathForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMultipathForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetAllMultipathForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
