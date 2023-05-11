
#include "gen/SetPrnForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPrnForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPrnForEachSV::CmdName = "SetPrnForEachSV";
    const char* const SetPrnForEachSV::Documentation = "Set the PRN for each satellite for specified signals.";

    REGISTER_COMMAND_FACTORY(SetPrnForEachSV);


    SetPrnForEachSV::SetPrnForEachSV()
      : CommandBase(CmdName)
    {}

    SetPrnForEachSV::SetPrnForEachSV(const std::string& signal, const std::vector<int>& prn)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setPrn(prn);
    }

    SetPrnForEachSVPtr SetPrnForEachSV::create(const std::string& signal, const std::vector<int>& prn)
    {
      return std::make_shared<SetPrnForEachSV>(signal, prn);
    }

    SetPrnForEachSVPtr SetPrnForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPrnForEachSV>(ptr);
    }

    bool SetPrnForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<int>>::is_valid(m_values["Prn"])
        ;

    }

    std::string SetPrnForEachSV::documentation() const { return Documentation; }


    int SetPrnForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPrnForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetPrnForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetPrnForEachSV::prn() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Prn"]);
    }

    void SetPrnForEachSV::setPrn(const std::vector<int>& prn)
    {
      m_values.AddMember("Prn", parse_json<std::vector<int>>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
