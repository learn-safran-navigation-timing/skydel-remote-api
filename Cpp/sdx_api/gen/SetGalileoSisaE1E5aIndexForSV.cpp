
#include "SetGalileoSisaE1E5aIndexForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSisaE1E5aIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSisaE1E5aIndexForSV::CmdName = "SetGalileoSisaE1E5aIndexForSV";
    const char* const SetGalileoSisaE1E5aIndexForSV::Documentation = "Set the SISA(E1,E5a) index of a Galileo satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Sisai       int             SISA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGalileoSisaE1E5aIndexForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGalileoSisaE1E5aIndexForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGalileoSisaE1E5aIndexForSV);


    SetGalileoSisaE1E5aIndexForSV::SetGalileoSisaE1E5aIndexForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGalileoSisaE1E5aIndexForSV::SetGalileoSisaE1E5aIndexForSV(int svId, int sisai, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setSisai(sisai);
      setDataSetName(dataSetName);
    }

    SetGalileoSisaE1E5aIndexForSVPtr SetGalileoSisaE1E5aIndexForSV::create(int svId, int sisai, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGalileoSisaE1E5aIndexForSV>(svId, sisai, dataSetName);
    }

    SetGalileoSisaE1E5aIndexForSVPtr SetGalileoSisaE1E5aIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSisaE1E5aIndexForSV>(ptr);
    }

    bool SetGalileoSisaE1E5aIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Sisai"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoSisaE1E5aIndexForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGalileoSisaE1E5aIndexForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Sisai", "DataSetName"}; 
      return names; 
    }


    int SetGalileoSisaE1E5aIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGalileoSisaE1E5aIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGalileoSisaE1E5aIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSisaE1E5aIndexForSV::sisai() const
    {
      return parse_json<int>::parse(m_values["Sisai"]);
    }

    void SetGalileoSisaE1E5aIndexForSV::setSisai(int sisai)
    {
      m_values.AddMember("Sisai", parse_json<int>::format(sisai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGalileoSisaE1E5aIndexForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoSisaE1E5aIndexForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
