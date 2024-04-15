#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Rename a space vehicle antenna model.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// Name    string Reference space vehicle antenna model name
    /// NewName string New space vehicle antenna model name
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class RenameSVAntennaModel;
    typedef std::shared_ptr<RenameSVAntennaModel> RenameSVAntennaModelPtr;
    
    
    class RenameSVAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RenameSVAntennaModel();

      RenameSVAntennaModel(const std::string& name, const std::string& newName, const std::string& system);

      static RenameSVAntennaModelPtr create(const std::string& name, const std::string& newName, const std::string& system);
      static RenameSVAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** newName ****
      std::string newName() const;
      void setNewName(const std::string& newName);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

