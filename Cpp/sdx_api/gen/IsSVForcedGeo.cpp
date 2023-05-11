
#include "gen/IsSVForcedGeo.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSVForcedGeo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSVForcedGeo::CmdName = "IsSVForcedGeo";
    const char* const IsSVForcedGeo::Documentation = "Get whether a satellite is geostationary";

    REGISTER_COMMAND_FACTORY(IsSVForcedGeo);


    IsSVForcedGeo::IsSVForcedGeo()
      : CommandBase(CmdName)
    {}

    IsSVForcedGeo::IsSVForcedGeo(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    IsSVForcedGeoPtr IsSVForcedGeo::create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<IsSVForcedGeo>(system, svId, dataSetName);
    }

    IsSVForcedGeoPtr IsSVForcedGeo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSVForcedGeo>(ptr);
    }

    bool IsSVForcedGeo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string IsSVForcedGeo::documentation() const { return Documentation; }


    int IsSVForcedGeo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSVForcedGeo::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSVForcedGeo::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSVForcedGeo::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSVForcedGeo::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> IsSVForcedGeo::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void IsSVForcedGeo::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
