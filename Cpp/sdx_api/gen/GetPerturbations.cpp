
#include "GetPerturbations.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbations
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbations::CmdName = "GetPerturbations";
    const char* const GetPerturbations::Documentation = "Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for the specified constellation.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId        int             The satellite's SV ID.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPerturbations::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPerturbations);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPerturbations);


    GetPerturbations::GetPerturbations()
      : CommandBase(CmdName, TargetId)
    {}

    GetPerturbations::GetPerturbations(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetPerturbationsPtr GetPerturbations::create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPerturbations>(system, svId, dataSetName);
    }

    GetPerturbationsPtr GetPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPerturbations>(ptr);
    }

    bool GetPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPerturbations::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPerturbations::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "DataSetName"}; 
      return names; 
    }


    int GetPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPerturbations::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPerturbations::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPerturbations::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPerturbations::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetPerturbations::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPerturbations::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
