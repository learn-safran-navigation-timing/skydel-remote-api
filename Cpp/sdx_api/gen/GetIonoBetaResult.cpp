
#include "GetIonoBetaResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoBetaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoBetaResult::CmdName = "GetIonoBetaResult";
    const char* const GetIonoBetaResult::Documentation = "Result of GetIonoBeta.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------\n"
      "Index int    Coefficient index [0..3]\n"
      "Val   double Coefficient value";
    const char* const GetIonoBetaResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoBetaResult);


    GetIonoBetaResult::GetIonoBetaResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoBetaResult::GetIonoBetaResult(int index, double val)
      : CommandResult(CmdName, TargetId)
    {

      setIndex(index);
      setVal(val);
    }

    GetIonoBetaResult::GetIonoBetaResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIndex(index);
      setVal(val);
    }


    GetIonoBetaResultPtr GetIonoBetaResult::create(int index, double val)
    {
      return std::make_shared<GetIonoBetaResult>(index, val);
    }

    GetIonoBetaResultPtr GetIonoBetaResult::create(CommandBasePtr relatedCommand, int index, double val)
    {
      return std::make_shared<GetIonoBetaResult>(relatedCommand, index, val);
    }

    GetIonoBetaResultPtr GetIonoBetaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoBetaResult>(ptr);
    }

    bool GetIonoBetaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetIonoBetaResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoBetaResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index", "Val"}; 
      return names; 
    }


    int GetIonoBetaResult::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoBetaResult::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIonoBetaResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetIonoBetaResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
