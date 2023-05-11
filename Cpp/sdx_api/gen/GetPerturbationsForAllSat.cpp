
#include "gen/GetPerturbationsForAllSat.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbationsForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbationsForAllSat::CmdName = "GetPerturbationsForAllSat";
    const char* const GetPerturbationsForAllSat::Documentation = "Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..\nAll parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";

    REGISTER_COMMAND_FACTORY(GetPerturbationsForAllSat);


    GetPerturbationsForAllSat::GetPerturbationsForAllSat()
      : CommandBase(CmdName)
    {}

    GetPerturbationsForAllSat::GetPerturbationsForAllSat(const std::string& system, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }

    GetPerturbationsForAllSatPtr GetPerturbationsForAllSat::create(const std::string& system, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPerturbationsForAllSat>(system, dataSetName);
    }

    GetPerturbationsForAllSatPtr GetPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPerturbationsForAllSat>(ptr);
    }

    bool GetPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPerturbationsForAllSat::documentation() const { return Documentation; }


    int GetPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPerturbationsForAllSat::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPerturbationsForAllSat::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetPerturbationsForAllSat::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPerturbationsForAllSat::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
