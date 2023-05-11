
#include "gen/ResetPerturbations.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetPerturbations
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetPerturbations::CmdName = "ResetPerturbations";
    const char* const ResetPerturbations::Documentation = "Set orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero for the specified constellation.";

    REGISTER_COMMAND_FACTORY(ResetPerturbations);


    ResetPerturbations::ResetPerturbations()
      : CommandBase(CmdName)
    {}

    ResetPerturbations::ResetPerturbations(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    ResetPerturbationsPtr ResetPerturbations::create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<ResetPerturbations>(system, svId, dataSetName);
    }

    ResetPerturbationsPtr ResetPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetPerturbations>(ptr);
    }

    bool ResetPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string ResetPerturbations::documentation() const { return Documentation; }


    int ResetPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ResetPerturbations::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ResetPerturbations::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ResetPerturbations::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void ResetPerturbations::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ResetPerturbations::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void ResetPerturbations::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
