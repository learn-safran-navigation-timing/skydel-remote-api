
#include "SetPerturbationsForAllSat.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPerturbationsForAllSat
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPerturbationsForAllSat::CmdName = "SetPerturbationsForAllSat";
    const char* const SetPerturbationsForAllSat::Documentation = "Set orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..\n"
      "All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Crs         array double    Crs (meter)\n"
      "Crc         array double    Crc (meter)\n"
      "Cis         array double    Cis (rad)\n"
      "Cic         array double    Cic (rad)\n"
      "Cus         array double    Cus (rad)\n"
      "Cuc         array double    Cuc (rad)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetPerturbationsForAllSat::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPerturbationsForAllSat);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPerturbationsForAllSat);


    SetPerturbationsForAllSat::SetPerturbationsForAllSat()
      : CommandBase(CmdName, TargetId)
    {}

    SetPerturbationsForAllSat::SetPerturbationsForAllSat(const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
      setDataSetName(dataSetName);
    }

    SetPerturbationsForAllSatPtr SetPerturbationsForAllSat::create(const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetPerturbationsForAllSat>(system, crs, crc, cis, cic, cus, cuc, dataSetName);
    }

    SetPerturbationsForAllSatPtr SetPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPerturbationsForAllSat>(ptr);
    }

    bool SetPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<double>>::is_valid(m_values["Crs"])
          && parse_json<std::vector<double>>::is_valid(m_values["Crc"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cis"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cic"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cus"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cuc"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetPerturbationsForAllSat::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPerturbationsForAllSat::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Crs", "Crc", "Cis", "Cic", "Cus", "Cuc", "DataSetName"}; 
      return names; 
    }


    int SetPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPerturbationsForAllSat::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPerturbationsForAllSat::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPerturbationsForAllSat::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void SetPerturbationsForAllSat::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPerturbationsForAllSat::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void SetPerturbationsForAllSat::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPerturbationsForAllSat::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void SetPerturbationsForAllSat::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPerturbationsForAllSat::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void SetPerturbationsForAllSat::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPerturbationsForAllSat::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void SetPerturbationsForAllSat::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPerturbationsForAllSat::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void SetPerturbationsForAllSat::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetPerturbationsForAllSat::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetPerturbationsForAllSat::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
