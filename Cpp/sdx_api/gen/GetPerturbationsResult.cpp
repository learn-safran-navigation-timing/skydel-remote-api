
#include "gen/GetPerturbationsResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbationsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbationsResult::CmdName = "GetPerturbationsResult";
    const char* const GetPerturbationsResult::Documentation = "Result of GetPerturbations.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetPerturbationsResult);


    GetPerturbationsResult::GetPerturbationsResult()
      : CommandResult(CmdName)
    {}

    GetPerturbationsResult::GetPerturbationsResult(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
      setDataSetName(dataSetName);
    }

    GetPerturbationsResult::GetPerturbationsResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
      setDataSetName(dataSetName);
    }


    GetPerturbationsResultPtr GetPerturbationsResult::create(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPerturbationsResult>(system, svId, crs, crc, cis, cic, cus, cuc, dataSetName);
    }

    GetPerturbationsResultPtr GetPerturbationsResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPerturbationsResult>(relatedCommand, system, svId, crs, crc, cis, cic, cus, cuc, dataSetName);
    }

    GetPerturbationsResultPtr GetPerturbationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPerturbationsResult>(ptr);
    }

    bool GetPerturbationsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["Crs"])
          && parse_json<double>::is_valid(m_values["Crc"])
          && parse_json<double>::is_valid(m_values["Cis"])
          && parse_json<double>::is_valid(m_values["Cic"])
          && parse_json<double>::is_valid(m_values["Cus"])
          && parse_json<double>::is_valid(m_values["Cuc"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPerturbationsResult::documentation() const { return Documentation; }


    std::string GetPerturbationsResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPerturbationsResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPerturbationsResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPerturbationsResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPerturbationsResult::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void GetPerturbationsResult::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPerturbationsResult::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void GetPerturbationsResult::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPerturbationsResult::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void GetPerturbationsResult::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPerturbationsResult::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void GetPerturbationsResult::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPerturbationsResult::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void GetPerturbationsResult::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPerturbationsResult::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void GetPerturbationsResult::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetPerturbationsResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPerturbationsResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
