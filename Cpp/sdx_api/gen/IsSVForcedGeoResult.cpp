
#include "gen/IsSVForcedGeoResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSVForcedGeoResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSVForcedGeoResult::CmdName = "IsSVForcedGeoResult";
    const char* const IsSVForcedGeoResult::Documentation = "Result of IsSVForcedGeo.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsSVForcedGeoResult);


    IsSVForcedGeoResult::IsSVForcedGeoResult()
      : CommandResult(CmdName)
    {}

    IsSVForcedGeoResult::IsSVForcedGeoResult(const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setIsGeo(isGeo);
      setLongitude(longitude);
      setDataSetName(dataSetName);
    }

    IsSVForcedGeoResult::IsSVForcedGeoResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setIsGeo(isGeo);
      setLongitude(longitude);
      setDataSetName(dataSetName);
    }


    IsSVForcedGeoResultPtr IsSVForcedGeoResult::create(const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<IsSVForcedGeoResult>(system, svId, isGeo, longitude, dataSetName);
    }

    IsSVForcedGeoResultPtr IsSVForcedGeoResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<IsSVForcedGeoResult>(relatedCommand, system, svId, isGeo, longitude, dataSetName);
    }

    IsSVForcedGeoResultPtr IsSVForcedGeoResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSVForcedGeoResult>(ptr);
    }

    bool IsSVForcedGeoResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["IsGeo"])
          && parse_json<double>::is_valid(m_values["Longitude"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string IsSVForcedGeoResult::documentation() const { return Documentation; }


    std::string IsSVForcedGeoResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSVForcedGeoResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSVForcedGeoResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSVForcedGeoResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSVForcedGeoResult::isGeo() const
    {
      return parse_json<bool>::parse(m_values["IsGeo"]);
    }

    void IsSVForcedGeoResult::setIsGeo(bool isGeo)
    {
      m_values.AddMember("IsGeo", parse_json<bool>::format(isGeo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double IsSVForcedGeoResult::longitude() const
    {
      return parse_json<double>::parse(m_values["Longitude"]);
    }

    void IsSVForcedGeoResult::setLongitude(double longitude)
    {
      m_values.AddMember("Longitude", parse_json<double>::format(longitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> IsSVForcedGeoResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void IsSVForcedGeoResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
