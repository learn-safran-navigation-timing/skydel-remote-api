
#include "GetSVAntennaGain.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaGain::CmdName = "GetSVAntennaGain";
    const char* const GetSVAntennaGain::Documentation = "Get space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.\n"
      "\n"
      "Name   Type            Description\n"
      "------ --------------- --------------------------------------------------------------------------\n"
      "Band   GNSSBand        Frequency band\n"
      "System string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Name   optional string SV antenna name";
    const char* const GetSVAntennaGain::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVAntennaGain);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVAntennaGain);


    GetSVAntennaGain::GetSVAntennaGain()
      : CommandBase(CmdName, TargetId)
    {}

    GetSVAntennaGain::GetSVAntennaGain(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setSystem(system);
      setName(name);
    }

    GetSVAntennaGainPtr GetSVAntennaGain::create(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& name)
    {
      return std::make_shared<GetSVAntennaGain>(band, system, name);
    }

    GetSVAntennaGainPtr GetSVAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaGain>(ptr);
    }

    bool GetSVAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetSVAntennaGain::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVAntennaGain::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "System", "Name"}; 
      return names; 
    }


    int GetSVAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetSVAntennaGain::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVAntennaGain::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaGain::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaGain::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetSVAntennaGain::name() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetSVAntennaGain::setName(const std::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
