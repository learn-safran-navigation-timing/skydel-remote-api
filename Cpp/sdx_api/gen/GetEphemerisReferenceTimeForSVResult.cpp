
#include "GetEphemerisReferenceTimeForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisReferenceTimeForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisReferenceTimeForSVResult::CmdName = "GetEphemerisReferenceTimeForSVResult";
    const char* const GetEphemerisReferenceTimeForSVResult::Documentation = "Result of GetEphemerisReferenceTimeForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId        int             The satellite's SV ID.\n"
      "Time        datetime        GPS date and time (it is the GPS time expressed in UTC format)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetEphemerisReferenceTimeForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisReferenceTimeForSVResult);


    GetEphemerisReferenceTimeForSVResult::GetEphemerisReferenceTimeForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEphemerisReferenceTimeForSVResult::GetEphemerisReferenceTimeForSVResult(const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setTime(time);
      setDataSetName(dataSetName);
    }

    GetEphemerisReferenceTimeForSVResult::GetEphemerisReferenceTimeForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setTime(time);
      setDataSetName(dataSetName);
    }


    GetEphemerisReferenceTimeForSVResultPtr GetEphemerisReferenceTimeForSVResult::create(const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetEphemerisReferenceTimeForSVResult>(system, svId, time, dataSetName);
    }

    GetEphemerisReferenceTimeForSVResultPtr GetEphemerisReferenceTimeForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetEphemerisReferenceTimeForSVResult>(relatedCommand, system, svId, time, dataSetName);
    }

    GetEphemerisReferenceTimeForSVResultPtr GetEphemerisReferenceTimeForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisReferenceTimeForSVResult>(ptr);
    }

    bool GetEphemerisReferenceTimeForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetEphemerisReferenceTimeForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisReferenceTimeForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Time", "DataSetName"}; 
      return names; 
    }


    std::string GetEphemerisReferenceTimeForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisReferenceTimeForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisReferenceTimeForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisReferenceTimeForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetEphemerisReferenceTimeForSVResult::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void GetEphemerisReferenceTimeForSVResult::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetEphemerisReferenceTimeForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetEphemerisReferenceTimeForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
