
#include "SetPrnForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPrnForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPrnForEachSV::CmdName = "SetPrnForEachSV";
    const char* const SetPrnForEachSV::Documentation = "Set the PRN for each satellite for specified signals.\n"
      "\n"
      "Name   Type      Description\n"
      "------ --------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string    Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\", \"PULSARXL\"\n"
      "Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)";
    const char* const SetPrnForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPrnForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPrnForEachSV);


    SetPrnForEachSV::SetPrnForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPrnForEachSV::SetPrnForEachSV(const std::string& signal, const std::vector<int>& prn)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetPrnForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Prn"}; 
      return names; 
    }


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
