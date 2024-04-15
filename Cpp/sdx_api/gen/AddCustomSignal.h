#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Adds a custom signal
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------------------------
    /// Path string Path to the custom signal XML file
    /// Id   string Unique identifier automatically set by simulator
    ///

    class AddCustomSignal;
    typedef std::shared_ptr<AddCustomSignal> AddCustomSignalPtr;
    
    
    class AddCustomSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      AddCustomSignal();

      AddCustomSignal(const std::string& path, const std::string& id);

      static AddCustomSignalPtr create(const std::string& path, const std::string& id);
      static AddCustomSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

