
#include "gen/ForceSVGeo.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ForceSVGeo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ForceSVGeo::CmdName = "ForceSVGeo";
    const char* const ForceSVGeo::Documentation = "Set whether a satellite is geostationary";

    REGISTER_COMMAND_FACTORY(ForceSVGeo);


    ForceSVGeo::ForceSVGeo()
      : CommandBase(CmdName)
    {}

    ForceSVGeo::ForceSVGeo(const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setIsGeo(isGeo);
      setLongitude(longitude);
      setDataSetName(dataSetName);
    }

    ForceSVGeoPtr ForceSVGeo::create(const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<ForceSVGeo>(system, svId, isGeo, longitude, dataSetName);
    }

    ForceSVGeoPtr ForceSVGeo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ForceSVGeo>(ptr);
    }

    bool ForceSVGeo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["IsGeo"])
          && parse_json<double>::is_valid(m_values["Longitude"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string ForceSVGeo::documentation() const { return Documentation; }


    int ForceSVGeo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ForceSVGeo::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ForceSVGeo::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ForceSVGeo::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void ForceSVGeo::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ForceSVGeo::isGeo() const
    {
      return parse_json<bool>::parse(m_values["IsGeo"]);
    }

    void ForceSVGeo::setIsGeo(bool isGeo)
    {
      m_values.AddMember("IsGeo", parse_json<bool>::format(isGeo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double ForceSVGeo::longitude() const
    {
      return parse_json<double>::parse(m_values["Longitude"]);
    }

    void ForceSVGeo::setLongitude(double longitude)
    {
      m_values.AddMember("Longitude", parse_json<double>::format(longitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ForceSVGeo::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void ForceSVGeo::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
