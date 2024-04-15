
#include "IsSVForcedGeo.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSVForcedGeo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSVForcedGeo::CmdName = "IsSVForcedGeo";
    const char* const IsSVForcedGeo::Documentation = "Get whether a satellite is geostationary\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId        int             The satellite SV ID\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const IsSVForcedGeo::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSVForcedGeo);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSVForcedGeo);


    IsSVForcedGeo::IsSVForcedGeo()
      : CommandBase(CmdName, TargetId)
    {}

    IsSVForcedGeo::IsSVForcedGeo(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsSVForcedGeo::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "DataSetName"}; 
      return names; 
    }


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
