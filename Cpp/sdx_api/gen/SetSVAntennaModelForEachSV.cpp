
#include "SetSVAntennaModelForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaModelForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaModelForEachSV::CmdName = "SetSVAntennaModelForEachSV";
    const char* const SetSVAntennaModelForEachSV::Documentation = "Set the antenna model for all satellites.\n"
      "\n"
      "Name              Type         Description\n"
      "----------------- ------------ -----------------------------------------------------------------------------------------------------\n"
      "System            string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
    const char* const SetSVAntennaModelForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSVAntennaModelForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSVAntennaModelForEachSV);


    SetSVAntennaModelForEachSV::SetSVAntennaModelForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSVAntennaModelForEachSV::SetSVAntennaModelForEachSV(const std::string& system, const std::vector<std::string>& antennaModelNames)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setAntennaModelNames(antennaModelNames);
    }

    SetSVAntennaModelForEachSVPtr SetSVAntennaModelForEachSV::create(const std::string& system, const std::vector<std::string>& antennaModelNames)
    {
      return std::make_shared<SetSVAntennaModelForEachSV>(system, antennaModelNames);
    }

    SetSVAntennaModelForEachSVPtr SetSVAntennaModelForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaModelForEachSV>(ptr);
    }

    bool SetSVAntennaModelForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaModelNames"])
        ;

    }

    std::string SetSVAntennaModelForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSVAntennaModelForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "AntennaModelNames"}; 
      return names; 
    }


    int SetSVAntennaModelForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSVAntennaModelForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaModelForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> SetSVAntennaModelForEachSV::antennaModelNames() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["AntennaModelNames"]);
    }

    void SetSVAntennaModelForEachSV::setAntennaModelNames(const std::vector<std::string>& antennaModelNames)
    {
      m_values.AddMember("AntennaModelNames", parse_json<std::vector<std::string>>::format(antennaModelNames, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
