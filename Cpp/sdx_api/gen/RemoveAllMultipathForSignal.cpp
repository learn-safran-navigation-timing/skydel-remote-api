
#include "gen/RemoveAllMultipathForSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllMultipathForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllMultipathForSignal::CmdName = "RemoveAllMultipathForSignal";
    const char* const RemoveAllMultipathForSignal::Documentation = "Disable all multipath in all satellites but only for the specified signal.";

    REGISTER_COMMAND_FACTORY(RemoveAllMultipathForSignal);


    RemoveAllMultipathForSignal::RemoveAllMultipathForSignal()
      : CommandBase(CmdName)
    {}

    RemoveAllMultipathForSignal::RemoveAllMultipathForSignal(const std::string& signal, bool reset)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setReset(reset);
    }

    RemoveAllMultipathForSignalPtr RemoveAllMultipathForSignal::create(const std::string& signal, bool reset)
    {
      return std::make_shared<RemoveAllMultipathForSignal>(signal, reset);
    }

    RemoveAllMultipathForSignalPtr RemoveAllMultipathForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllMultipathForSignal>(ptr);
    }

    bool RemoveAllMultipathForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Reset"])
        ;

    }

    std::string RemoveAllMultipathForSignal::documentation() const { return Documentation; }


    int RemoveAllMultipathForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllMultipathForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void RemoveAllMultipathForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool RemoveAllMultipathForSignal::reset() const
    {
      return parse_json<bool>::parse(m_values["Reset"]);
    }

    void RemoveAllMultipathForSignal::setReset(bool reset)
    {
      m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
