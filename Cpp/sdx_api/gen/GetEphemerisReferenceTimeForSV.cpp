
#include "GetEphemerisReferenceTimeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisReferenceTimeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisReferenceTimeForSV::CmdName = "GetEphemerisReferenceTimeForSV";
    const char* const GetEphemerisReferenceTimeForSV::Documentation = "Get the ephemeris reference time for the specified constellation.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId        int             The satellite's SV ID.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetEphemerisReferenceTimeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEphemerisReferenceTimeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisReferenceTimeForSV);


    GetEphemerisReferenceTimeForSV::GetEphemerisReferenceTimeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetEphemerisReferenceTimeForSV::GetEphemerisReferenceTimeForSV(const std::string& system, int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetEphemerisReferenceTimeForSVPtr GetEphemerisReferenceTimeForSV::create(const std::string& system, int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetEphemerisReferenceTimeForSV>(system, svId, dataSetName);
    }

    GetEphemerisReferenceTimeForSVPtr GetEphemerisReferenceTimeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisReferenceTimeForSV>(ptr);
    }

    bool GetEphemerisReferenceTimeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetEphemerisReferenceTimeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisReferenceTimeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "DataSetName"}; 
      return names; 
    }


    int GetEphemerisReferenceTimeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisReferenceTimeForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisReferenceTimeForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisReferenceTimeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisReferenceTimeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetEphemerisReferenceTimeForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetEphemerisReferenceTimeForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
