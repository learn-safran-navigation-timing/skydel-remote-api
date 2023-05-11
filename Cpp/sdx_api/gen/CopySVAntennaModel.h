#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Copy a space vehicle antenna model.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------
    /// Name     string Reference space vehicle antenna model name
    /// CopyName string Copy space vehicle antenna model name
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class CopySVAntennaModel;
    typedef std::shared_ptr<CopySVAntennaModel> CopySVAntennaModelPtr;
    
    
    class CopySVAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      CopySVAntennaModel();

      CopySVAntennaModel(const std::string& name, const std::string& copyName, const std::string& system);

      static CopySVAntennaModelPtr create(const std::string& name, const std::string& copyName, const std::string& system);
      static CopySVAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** copyName ****
      std::string copyName() const;
      void setCopyName(const std::string& copyName);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

