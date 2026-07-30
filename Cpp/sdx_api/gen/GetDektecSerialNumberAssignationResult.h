#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDektecSerialNumberAssignation.
    ///
    /// Name          Type         Description
    /// ------------- ------------ --------------------------------------------------------
    /// DektecType    string       Dektec type, valid values are "DTA-2115B" or "DTA-2116".
    /// SerialNumbers array string Dektec Serial Numbers
    ///

    class GetDektecSerialNumberAssignationResult;
    typedef std::shared_ptr<GetDektecSerialNumberAssignationResult> GetDektecSerialNumberAssignationResultPtr;
    
    
    class GetDektecSerialNumberAssignationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDektecSerialNumberAssignationResult();

      GetDektecSerialNumberAssignationResult(const std::string& dektecType, const std::vector<std::string>& serialNumbers);

      GetDektecSerialNumberAssignationResult(CommandBasePtr relatedCommand, const std::string& dektecType, const std::vector<std::string>& serialNumbers);

      static GetDektecSerialNumberAssignationResultPtr create(const std::string& dektecType, const std::vector<std::string>& serialNumbers);

      static GetDektecSerialNumberAssignationResultPtr create(CommandBasePtr relatedCommand, const std::string& dektecType, const std::vector<std::string>& serialNumbers);
      static GetDektecSerialNumberAssignationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** dektecType ****
      std::string dektecType() const;
      void setDektecType(const std::string& dektecType);


      // **** serialNumbers ****
      std::vector<std::string> serialNumbers() const;
      void setSerialNumbers(const std::vector<std::string>& serialNumbers);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetDektecSerialNumberAssignationResult);
  }
}

