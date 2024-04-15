
#include "GetQzssL1SAugmentationResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1SAugmentationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1SAugmentationResult::CmdName = "GetQzssL1SAugmentationResult";
    const char* const GetQzssL1SAugmentationResult::Documentation = "Result of GetQzssL1SAugmentation.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ ----------------------------------------------------------------------------------\n"
      "System     string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\" or \"QZSS\"\n"
      "Prn        int    Satellite PRN number.\n"
      "AugmentIOD bool   Include the satellite Issue Of Data in L1S message.\n"
      "AugmentPRC bool   Include the satellite Pseudorange Correction in L1S message.\n"
      "Prc        double Pseudorange Correction to include in L1S message. Only used if AugmentPSR is True.\n"
      "Id         string Unique identifier of the augmentation.";
    const char* const GetQzssL1SAugmentationResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1SAugmentationResult);


    GetQzssL1SAugmentationResult::GetQzssL1SAugmentationResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssL1SAugmentationResult::GetQzssL1SAugmentationResult(const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setPrn(prn);
      setAugmentIOD(augmentIOD);
      setAugmentPRC(augmentPRC);
      setPrc(prc);
      setId(id);
    }

    GetQzssL1SAugmentationResult::GetQzssL1SAugmentationResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setAugmentIOD(augmentIOD);
      setAugmentPRC(augmentPRC);
      setPrc(prc);
      setId(id);
    }


    GetQzssL1SAugmentationResultPtr GetQzssL1SAugmentationResult::create(const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id)
    {
      return std::make_shared<GetQzssL1SAugmentationResult>(system, prn, augmentIOD, augmentPRC, prc, id);
    }

    GetQzssL1SAugmentationResultPtr GetQzssL1SAugmentationResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id)
    {
      return std::make_shared<GetQzssL1SAugmentationResult>(relatedCommand, system, prn, augmentIOD, augmentPRC, prc, id);
    }

    GetQzssL1SAugmentationResultPtr GetQzssL1SAugmentationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1SAugmentationResult>(ptr);
    }

    bool GetQzssL1SAugmentationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["AugmentIOD"])
          && parse_json<bool>::is_valid(m_values["AugmentPRC"])
          && parse_json<double>::is_valid(m_values["Prc"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetQzssL1SAugmentationResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1SAugmentationResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Prn", "AugmentIOD", "AugmentPRC", "Prc", "Id"}; 
      return names; 
    }


    std::string GetQzssL1SAugmentationResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetQzssL1SAugmentationResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssL1SAugmentationResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetQzssL1SAugmentationResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL1SAugmentationResult::augmentIOD() const
    {
      return parse_json<bool>::parse(m_values["AugmentIOD"]);
    }

    void GetQzssL1SAugmentationResult::setAugmentIOD(bool augmentIOD)
    {
      m_values.AddMember("AugmentIOD", parse_json<bool>::format(augmentIOD, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL1SAugmentationResult::augmentPRC() const
    {
      return parse_json<bool>::parse(m_values["AugmentPRC"]);
    }

    void GetQzssL1SAugmentationResult::setAugmentPRC(bool augmentPRC)
    {
      m_values.AddMember("AugmentPRC", parse_json<bool>::format(augmentPRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssL1SAugmentationResult::prc() const
    {
      return parse_json<double>::parse(m_values["Prc"]);
    }

    void GetQzssL1SAugmentationResult::setPrc(double prc)
    {
      m_values.AddMember("Prc", parse_json<double>::format(prc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssL1SAugmentationResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetQzssL1SAugmentationResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
