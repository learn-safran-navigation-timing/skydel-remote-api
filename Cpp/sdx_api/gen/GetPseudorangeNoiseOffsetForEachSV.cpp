
#include "GetPseudorangeNoiseOffsetForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseOffsetForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseOffsetForEachSV::CmdName = "GetPseudorangeNoiseOffsetForEachSV";
    const char* const GetPseudorangeNoiseOffsetForEachSV::Documentation = "Get the satellite pseudorange noise constant offset for all satellites.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetPseudorangeNoiseOffsetForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseOffsetForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseOffsetForEachSV);


    GetPseudorangeNoiseOffsetForEachSV::GetPseudorangeNoiseOffsetForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPseudorangeNoiseOffsetForEachSV::GetPseudorangeNoiseOffsetForEachSV(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    GetPseudorangeNoiseOffsetForEachSVPtr GetPseudorangeNoiseOffsetForEachSV::create(const std::string& system)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForEachSV>(system);
    }

    GetPseudorangeNoiseOffsetForEachSVPtr GetPseudorangeNoiseOffsetForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseOffsetForEachSV>(ptr);
    }

    bool GetPseudorangeNoiseOffsetForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetPseudorangeNoiseOffsetForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseOffsetForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetPseudorangeNoiseOffsetForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseOffsetForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseOffsetForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
