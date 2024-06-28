
#include "GetPerturbationsForAllSat.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbationsForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbationsForAllSat::CmdName = "GetPerturbationsForAllSat";
    const char* const GetPerturbationsForAllSat::Documentation = "Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..\n"
      "All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPerturbationsForAllSat::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPerturbationsForAllSat);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPerturbationsForAllSat);


    GetPerturbationsForAllSat::GetPerturbationsForAllSat()
      : CommandBase(CmdName, TargetId)
    {}

    GetPerturbationsForAllSat::GetPerturbationsForAllSat(const std::string& system, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }

    GetPerturbationsForAllSatPtr GetPerturbationsForAllSat::create(const std::string& system, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPerturbationsForAllSat::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPerturbationsForAllSat::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetPerturbationsForAllSat::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPerturbationsForAllSat::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
