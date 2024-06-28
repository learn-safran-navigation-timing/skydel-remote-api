
#include "GetEphemerisReferenceTime.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisReferenceTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisReferenceTime::CmdName = "GetEphemerisReferenceTime";
    const char* const GetEphemerisReferenceTime::Documentation = "Please note the command GetEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n"
      "\n"
      "Get the ephemeris reference time for the specified constellation.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId        int             The satellite's SV ID.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetEphemerisReferenceTime::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEphemerisReferenceTime);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisReferenceTime);


    GetEphemerisReferenceTime::GetEphemerisReferenceTime()
      : CommandBase(CmdName, TargetId)
    {}

    GetEphemerisReferenceTime::GetEphemerisReferenceTime(const std::string& system, int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetEphemerisReferenceTimePtr GetEphemerisReferenceTime::create(const std::string& system, int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetEphemerisReferenceTime>(system, svId, dataSetName);
    }

    GetEphemerisReferenceTimePtr GetEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisReferenceTime>(ptr);
    }

    bool GetEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetEphemerisReferenceTime::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisReferenceTime::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "DataSetName"}; 
      return names; 
    }


    int GetEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisReferenceTime::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisReferenceTime::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisReferenceTime::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisReferenceTime::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetEphemerisReferenceTime::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetEphemerisReferenceTime::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
