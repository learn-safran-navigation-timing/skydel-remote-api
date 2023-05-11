
#include "gen/GetPerturbations.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbations
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbations::CmdName = "GetPerturbations";
    const char* const GetPerturbations::Documentation = "Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for the specified constellation.";

    REGISTER_COMMAND_FACTORY(GetPerturbations);


    GetPerturbations::GetPerturbations()
      : CommandBase(CmdName)
    {}

    GetPerturbations::GetPerturbations(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
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
