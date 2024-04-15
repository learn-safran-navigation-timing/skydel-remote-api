
#include "SetPseudorangeNoiseOffsetForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeNoiseOffsetForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeNoiseOffsetForEachSV::CmdName = "SetPseudorangeNoiseOffsetForEachSV";
    const char* const SetPseudorangeNoiseOffsetForEachSV::Documentation = "Set the satellite pseudorange noise constant offset for all satellites.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------\n"
      "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool   If true, the offset is enabled (applied)\n"
      "Offset  array double The constant offset in metters";
    const char* const SetPseudorangeNoiseOffsetForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPseudorangeNoiseOffsetForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPseudorangeNoiseOffsetForEachSV);


    SetPseudorangeNoiseOffsetForEachSV::SetPseudorangeNoiseOffsetForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPseudorangeNoiseOffsetForEachSV::SetPseudorangeNoiseOffsetForEachSV(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
      setOffset(offset);
    }

    SetPseudorangeNoiseOffsetForEachSVPtr SetPseudorangeNoiseOffsetForEachSV::create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
    {
      return std::make_shared<SetPseudorangeNoiseOffsetForEachSV>(system, enabled, offset);
    }

    SetPseudorangeNoiseOffsetForEachSVPtr SetPseudorangeNoiseOffsetForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeNoiseOffsetForEachSV>(ptr);
    }

    bool SetPseudorangeNoiseOffsetForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
          && parse_json<std::vector<double>>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPseudorangeNoiseOffsetForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPseudorangeNoiseOffsetForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled", "Offset"}; 
      return names; 
    }


    int SetPseudorangeNoiseOffsetForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeNoiseOffsetForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeNoiseOffsetForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetPseudorangeNoiseOffsetForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void SetPseudorangeNoiseOffsetForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPseudorangeNoiseOffsetForEachSV::offset() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Offset"]);
    }

    void SetPseudorangeNoiseOffsetForEachSV::setOffset(const std::vector<double>& offset)
    {
      m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
