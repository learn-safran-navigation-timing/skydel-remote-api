#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get  the Dektec serial number assignation for a Dektec type, indexed by device number.
    ///
    /// Name       Type   Description
    /// ---------- ------ --------------------------------------------------------
    /// DektecType string Dektec type, valid values are "DTA-2115B" or "DTA-2116".
    ///

    class GetDektecSerialNumberAssignation;
    typedef std::shared_ptr<GetDektecSerialNumberAssignation> GetDektecSerialNumberAssignationPtr;
    
    
    class GetDektecSerialNumberAssignation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDektecSerialNumberAssignation();

      GetDektecSerialNumberAssignation(const std::string& dektecType);

      static GetDektecSerialNumberAssignationPtr create(const std::string& dektecType);
      static GetDektecSerialNumberAssignationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** dektecType ****
      std::string dektecType() const;
      void setDektecType(const std::string& dektecType);
    };
    
  }
}

