#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set ionospheric model
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------------------------------------------
    /// Model string Ionospheric model ("None", "Klobuchar", "Spacecraft" or "NeQuick")
    ///

    class SetIonoModel;
    typedef std::shared_ptr<SetIonoModel> SetIonoModelPtr;
    
    
    class SetIonoModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIonoModel();

      SetIonoModel(const std::string& model);

      static SetIonoModelPtr create(const std::string& model);
      static SetIonoModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** model ****
      std::string model() const;
      void setModel(const std::string& model);
    };
    
  }
}

