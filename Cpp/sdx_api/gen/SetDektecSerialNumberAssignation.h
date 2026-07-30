#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set  the Dektec serial number assignation for a Dektec type, indexed by device number.
    ///
    /// Name          Type         Description
    /// ------------- ------------ --------------------------------------------------------
    /// DektecType    string       Dektec type, valid values are "DTA-2115B" or "DTA-2116".
    /// SerialNumbers array string Dektec Serial Numbers
    ///

    class SetDektecSerialNumberAssignation;
    typedef std::shared_ptr<SetDektecSerialNumberAssignation> SetDektecSerialNumberAssignationPtr;
    
    
    class SetDektecSerialNumberAssignation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetDektecSerialNumberAssignation();

      SetDektecSerialNumberAssignation(const std::string& dektecType, const std::vector<std::string>& serialNumbers);

      static SetDektecSerialNumberAssignationPtr create(const std::string& dektecType, const std::vector<std::string>& serialNumbers);
      static SetDektecSerialNumberAssignationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** dektecType ****
      std::string dektecType() const;
      void setDektecType(const std::string& dektecType);


      // **** serialNumbers ****
      std::vector<std::string> serialNumbers() const;
      void setSerialNumbers(const std::vector<std::string>& serialNumbers);
    };
    
  }
}

